//
// BAGEL - Parallel electron correlation program.
// Filename: relmofile.cc
// Copyright (C) 2013 Toru Shiozaki
//
// Author: Michael Caldwell <caldwell@u.northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// The BAGEL package is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public License
// along with the BAGEL package; see COPYING.  If not, write to
// the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <src/util/f77.h>
#include <src/zfci/relmofile.h>
#include <src/rel/dfock.h>
#include <src/rel/reldffull.h>
#include <src/rel/reloverlap.h>

using namespace std;
using namespace bagel;

RelMOFile::RelMOFile(const shared_ptr<const Reference> ref, const string method) : geom_(ref->geom()), ref_(dynamic_pointer_cast<const RelReference>(ref)) {
  // input should be RelReference
  assert(dynamic_pointer_cast<const RelReference>(ref));

  // density fitting is assumed
  assert(geom_->df());
}


// nstart and nfence are based on the convention in Dirac calculations
double RelMOFile::init(const int nstart, const int nfence) {
  // first compute all the AO integrals in core
  nbasis_ = geom_->nbasis();
  nocc_ = (nfence - nstart)/2;
  assert((nfence - nstart) % 2 == 0);
  geom_ = geom_->relativistic(ref_->gaunt());

  // then compute Kramers adapated coefficient matrices
  array<shared_ptr<ZMatrix>,2> coeff = kramers(nstart, nfence);

  // calculates the core fock matrix
  shared_ptr<const ZMatrix> hcore = make_shared<RelHcore>(geom_);
  if (nstart != 0) {
    shared_ptr<const ZMatrix> den = ref_->relcoeff()->distmatrix()->form_density_rhf(nstart)->matrix();
    core_fock_ = make_shared<DFock>(geom_, hcore, ref_->relcoeff()->slice(0, nstart), ref_->gaunt(), ref_->breit(), /*do_grad = */false);
    const complex<double> prod = (*den * (*hcore+*core_fock_)).trace();
    if (fabs(prod.imag()) > 1.0e-12) {
      stringstream ss; ss << "imaginary part of energy is nonzero!! Perhaps Fock is not Hermite for some reasons " << setprecision(10) << prod.imag();
      cout << ss.str() << endl;
    }
    core_energy_ = 0.5*prod.real();
  } else {
    core_fock_ = hcore; 
    core_energy_ = 0.0;
  }

  throw runtime_error("not yet implemented");
  return 0;
}


array<shared_ptr<ZMatrix>,2> RelMOFile::kramers(const int nstart, const int nfence) const {
  shared_ptr<const ZMatrix> coeff = ref_->relcoeff()->slice(nstart, nfence);
  shared_ptr<ZMatrix> reordered = coeff->clone();

  const int noff = reordered->mdim()/2;
  const int ndim = reordered->ndim();
  const int mdim = reordered->mdim();
  const int nb = ndim / 4;
  assert(nb == nbasis_);

  if ((nfence-nstart)%2 != 0 || ndim%4 != 0)
    throw logic_error("illegal call of RelMOFile::kramers");

  // overlap matrix
  auto overlap = make_shared<RelOverlap>(geom_);
  auto sigmaz = overlap->copy();
  sigmaz->add_block(-2.0, nb, nb, nb, nb, sigmaz->get_submatrix(nb,nb,nb,nb));
  sigmaz->add_block(-2.0, nb*3, nb*3, nb, nb, sigmaz->get_submatrix(nb*3,nb*3,nb,nb));
  // just for convenience
  sigmaz->scale(-1.0);

  unique_ptr<double[]> tmp(new double[mdim]);
  int i;
  for (i = 0; i != mdim; ) {
    const double eig = ref_->eig()[nstart+i];
    int j = i+1;
    // pick up degenerate orbitals
    while (j != mdim && (fabs(ref_->eig()[nstart+j]-eig) < 1.0e-8))
      ++j;
    assert((j-i)%2 == 0);
    const int n = j-i;

    auto cnow = coeff->slice(i, j);
    auto s = make_shared<ZMatrix>(*cnow % *sigmaz * *cnow);
    s->diagonalize(tmp.get());
    *cnow *= *s;

    assert(i%2 == 0);
    reordered->copy_block(0, i/2,      ndim, n/2, cnow->element_ptr(0, 0));
    reordered->copy_block(0, i/2+noff, ndim, n/2, cnow->element_ptr(0, n/2));
    i = j;
  }

  // fix the phase - making the largest element in each colomn real
  for (int i = 0; i != mdim; ++i) {
    complex<double> ele = *max_element(reordered->element_ptr(0,i), reordered->element_ptr(0,i+1), [](complex<double> a, complex<double> b) { return norm(a) < norm(b); });
    const complex<double> fac = norm(ele) / ele;
    transform(reordered->element_ptr(0,i), reordered->element_ptr(0,i+1), reordered->element_ptr(0,i), [&fac](complex<double> a) { return a*fac; });
  }

  // off diagonal
  auto zstar = reordered->get_submatrix(nb, 0, nb, noff)->get_conjg();
  auto ystar = reordered->get_submatrix(0, noff, nb, noff)->get_conjg();
  reordered->add_block(-1.0,  0, noff, nb, noff, zstar);
  reordered->add_block(-1.0, nb,    0, nb, noff, ystar);

  zstar = reordered->get_submatrix(nb*3, 0, nb, noff)->get_conjg();
  ystar = reordered->get_submatrix(nb*2, noff, nb, noff)->get_conjg();
  reordered->add_block(-1.0, nb*2, noff, nb, noff, zstar);
  reordered->add_block(-1.0, nb*3,    0, nb, noff, ystar);

  // diagonal
  reordered->add_block(1.0, 0, 0, nb, noff, reordered->get_submatrix(nb, noff, nb, noff)->get_conjg());
  reordered->copy_block(nb, noff, nb, noff, reordered->get_submatrix(0, 0, nb, noff)->get_conjg());
  reordered->add_block(1.0, nb*2, 0, nb, noff, reordered->get_submatrix(nb*3, noff, nb, noff)->get_conjg());
  reordered->copy_block(nb*3, noff, nb, noff, reordered->get_submatrix(nb*2, 0, nb, noff)->get_conjg());

  reordered->scale(0.5);

  array<shared_ptr<ZMatrix>,2> out{{reordered->slice(0,noff), reordered->slice(noff, noff*2)}};

  auto diag = (*out[0] % *overlap * *out[0]).diag();
  for (int i = 0; i != noff; ++i) {
    for (int j = 0; j != ndim; ++j) {
      out[0]->element(j,i) /= sqrt(diag[i].real());
      out[1]->element(j,i) /= sqrt(diag[i].real());
    }
  }
  return out;
}


#if 0
//TODO input matrices are now in block diagonal form and the sizes must be checked
void RelMOFile::compress(shared_ptr<const ZMatrix> buf1e, shared_ptr<const ZMatrix> buf2e) {

  const int nocc = norb_rel_;
  sizeij_ = nocc*nocc;
  mo2e_ = unique_ptr<complex<double>[]>(new complex<double>[sizeij_*sizeij_]);
  copy_n(buf2e->data(), sizeij_*sizeij_, mo2e_.get());

  // h'ij = hij - 0.5 sum_k (ik|kj)
  const int size1e = nocc*nocc;
  mo1e_ = unique_ptr<complex<double>[]>(new complex<double>[size1e]);
  int ij = 0;
  for (int i = 0; i != nocc; ++i) {
    for (int j = 0; j != nocc; ++j, ++ij) {
      mo1e_[ij] = buf1e->element(j,i);
      for (int k = 0; k != nocc; ++k)
        mo1e_[ij] -= 0.5*buf2e->data(j+k*nocc+k*nocc*nocc+i*nocc*nocc*nocc);
    }
  }
}
#endif


#if 0
tuple<shared_ptr<const ZMatrix>, double> RelJop::compute_mo1e(const int nstart, const int nfence) {
  throw runtime_error("not yet implemented");
  return make_tuple(shared_ptr<const ZMatrix>(), 0.0);
}
#endif


#if 0
shared_ptr<const ZMatrix> RelJop::compute_mo2e(const int nstart, const int nfence) {
  const size_t norb_rel_ = nfence - nstart;
  if (norb_rel_ < 1) throw runtime_error("no correlated electrons");

  auto relref = dynamic_pointer_cast<const RelReference>(ref_);
  assert(geom_->nbasis()*4 == relref->relcoeff()->ndim());
  assert(geom_->nbasis()*2 == relref->relcoeff()->mdim());

  // Separate Coefficients into real and imaginary
  // correlated occupied orbitals
  array<shared_ptr<const Matrix>, 4> rocoeff;
  array<shared_ptr<const Matrix>, 4> iocoeff;
  for (int i = 0; i != 4; ++i) {
    const size_t nbasis = geom_->nbasis();
    shared_ptr<const ZMatrix> oc = relref->relcoeff()->get_submatrix(i*nbasis, nstart, nbasis, nfence);
    rocoeff[i] = oc->get_real_part();
    iocoeff[i] = oc->get_imag_part();
  }

  // (1) make DFDists
  vector<shared_ptr<const DFDist>> dfs;
  dfs = geom_->dfs()->split_blocks();
  dfs.push_back(geom_->df());
  list<shared_ptr<RelDF>> dfdists = DFock::make_dfdists(dfs, false);

  // (2) first-transform
  list<shared_ptr<RelDFHalf>> half_complex = DFock::make_half_complex(dfdists, rocoeff, iocoeff);
  for (auto& i : half_complex)
    i = i->apply_J();

  // (3) split and factorize
  list<shared_ptr<RelDFHalf>> half_complex_exch;
  for (auto& i : half_complex) {
    list<shared_ptr<RelDFHalf>> tmp = i->split(false);
    half_complex_exch.insert(half_complex_exch.end(), tmp.begin(), tmp.end());
  }
  half_complex.clear();
  DFock::factorize(half_complex_exch);

  // (4) compute (gamma|ii)
  list<shared_ptr<RelDFFull>> dffull;
  for (auto& i : half_complex_exch)
    dffull.push_back(make_shared<RelDFFull>(i, rocoeff, iocoeff));
  DFock::factorize(dffull);
  dffull.front()->scale(dffull.front()->fac()); // take care of the factor
  assert(dffull.size() == 1);
  shared_ptr<const RelDFFull> full = dffull.front();

  shared_ptr<const ZMatrix> buf = full->form_4index(full, 1.0);

  return buf;
}
#endif
