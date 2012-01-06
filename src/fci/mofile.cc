//
// Author : Toru Shiozaki
// Date   : Dec 2011
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <src/util/f77.h>
#include <src/fci/mofile.h>
#include <src/rysint/eribatch.h>
#include <src/scf/scf.h>

using namespace std;

typedef std::shared_ptr<Atom> RefAtom;
typedef std::shared_ptr<Shell> RefShell;

MOFile::MOFile(const shared_ptr<Geometry> geom, const shared_ptr<Reference> ref) : geom_(geom), ref_(ref),
    core_fock_(new double[geom->nbasis()*geom->nbasis()]) {

  do_df_ = geom->df().get();
  if (!do_df_) throw runtime_error("for the time being I gave up maintaining non-DF codes.");

}

MOFile::~MOFile() {
}



double MOFile::create_Jiiii(const int nstart, const int nfence) {

  // first compute all the AO integrals in core
  nocc_ = nfence - nstart;
  nbasis_ = geom_->nbasis(); // size_t quantity :-)
  const int nbasis = nbasis_;
  const int nocc = nocc_;
  const int size = basis_.size(); // number of shells
  const size_t aointsize = nbasis_*nbasis*nbasis*nbasis; 

  unique_ptr<double[]> firstp;
  unique_ptr<double[]> aobuffp;

  unique_ptr<double[]> aobuff_(new double[nbasis*nbasis]);
  unique_ptr<double[]> first_(new double[nocc*nocc*nocc*nocc]);
  firstp = move(first_);
  aobuffp = move(aobuff_);

  double* first = firstp.get();
  double* aobuff = aobuffp.get();

  // some stuffs for blas
  double* cdata = ref_->coeff()->data() + nstart*nbasis;
  const int mm = nocc*nocc;

  // one electron part
  double core_energy = 0.0;
  {
    const bool df_ = do_df_;
    shared_ptr<Fock<1> > fock0(new Fock<1>(geom_, ref_->hcore()));
    if (nstart != 0) {
      shared_ptr<Matrix1e> den(new Matrix1e(ref_->coeff()->form_core_density_rhf()));
      shared_ptr<Fock<1> > fock1(new Fock<1>(geom_, fock0, den, ref_->schwarz()));
      core_energy = (*den * (*ref_->hcore()+*fock1)).trace();
      fock0 = fock1;
      dcopy_(nbasis*nbasis, fock1->data(), 1, core_fock_ptr(), 1);
    }
    fock0->symmetrize();
    dgemm_("n","n",nbasis,nocc,nbasis,1.0,fock0->data(),nbasis,cdata,nbasis,0.0,aobuff,nbasis);
  }
  unique_ptr<double[]> mo1e__(new double[nocc*nocc]);
  mo1e_ = move(mo1e__);
  dgemm_("t","n",nocc,nocc,nbasis,1.0,cdata,nbasis,aobuff,nbasis,0.0,mo1e_ptr(),nocc);


  //
  // two electron part.
  //

  shared_ptr<DensityFit> dff = geom_->df();

  // first half transformation
  shared_ptr<DF_Half> half = dff->compute_half_transform(cdata, nocc);

  // second index transformation and (D|ii) = J^-1/2_DE (E|ii)
  shared_ptr<DF_Full> buf = half->compute_second_transform(cdata, nocc)->apply_J();

  // assembles (ii|ii) = (ii|D)(D|ii)
  buf->form_4index(firstp);

  // we want to store half-transformed quantity for latter convenience
  mo2e_1ext_size_ = nocc*dff->naux()*nbasis;
  mo2e_1ext_ = half;


  // mo2e is compressed
  sizeij_ = nocc*(nocc+1)/2;
  unique_ptr<double[]> mo2e__(new double[sizeij_*sizeij_]);
  mo2e_ = move(mo2e__);

  int ijkl = 0;
  for (int i = 0; i != nocc; ++i) {
    for (int j = 0; j <= i; ++j) {
      const int ijo = (j + i*nocc)*nocc*nocc;
      for (int k = 0; k != nocc; ++k) {
        for (int l = 0; l <= k; ++l, ++ijkl) {
          mo2e_[ijkl] = first[l+k*nocc+ijo]; 
        }
      }
    }
  }

  // h'kl = hkl - 0.5 sum_j (kj|jl)
  unique_ptr<double[]> buf3(new double[sizeij_]);
  int ij = 0;
  for (int i=0; i!=nocc; ++i) {
    for (int j=0; j<=i; ++j, ++ij) {
      buf3[ij] = mo1e_[j+i*nocc];
      for (int k=0; k!=nocc; ++k) {
        buf3[ij] -= 0.5*first[(k+j*nocc)*mm+(k+i*nocc)];
      }
    }
  }
  mo1e_ = move(buf3);
  return core_energy;
}


void MOFile::update_1ext_ints(const vector<double>& coeff) {
  // in the case of no DF
  shared_ptr<DF_Half> buf = mo2e_1ext_->clone();

  // half transformed DF is rotated.
  const int naux = geom_->df()->naux();
  for (int i = 0; i != nbasis_; ++i) 
    dgemm_("N", "N", naux, nocc_, nocc_, 1.0, mo2e_1ext_->data()+i*naux*nocc_, naux, &(coeff[0]), nocc_, 0.0, buf->data()+i*naux*nocc_, naux); 
  mo2e_1ext_ = buf;

}
