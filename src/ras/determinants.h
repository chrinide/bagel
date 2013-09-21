//
// BAGEL - Parallel electron correlation program.
// Filename: ras/determinants.h
// Copyright (C) 2013 Toru Shiozaki
//
// Author: Shane Parker <shane.parker@u.northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
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


#ifndef __SRC_RAS_DETERMINANTS_H
#define __SRC_RAS_DETERMINANTS_H

#include <tuple>
#include <memory>

#include <src/ras/stringspace.h>

namespace bagel {
  namespace RAS {
    struct DMap {
      size_t source;
      size_t target;
      size_t ij;     // displacement operators
      int sign;      // sign of displacement

      DMap(const size_t s, const size_t t, const size_t ii, const int sn) : source(s), target(t), ij(ii), sign(sn) {}
    };
  }

class RASDeterminants : public std::enable_shared_from_this<RASDeterminants> {
  protected:

    std::array<int, 3> ras_;
    const int norb_;
    const int nelea_;
    const int neleb_;
    const int max_holes_;
    const int max_particles_;

    const int lenholes_; // number of combinations of holes
    const int lenparts_; // number of combinations of particles

    size_t size_;

    std::weak_ptr<RASDeterminants> addalpha_;
    std::weak_ptr<RASDeterminants> remalpha_;
    std::weak_ptr<RASDeterminants> addbeta_;
    std::weak_ptr<RASDeterminants> rembeta_;

    std::vector<std::vector<RAS::DMap>> phia_;
    std::vector<std::vector<RAS::DMap>> phib_;

    std::vector<std::vector<RAS::DMap>> phia_ij_;
    std::vector<std::vector<RAS::DMap>> phib_ij_;

    std::vector<std::vector<RAS::DMap>> phiupa_;
    std::vector<std::vector<RAS::DMap>> phiupb_;

    std::vector<std::vector<RAS::DMap>> phidowna_;
    std::vector<std::vector<RAS::DMap>> phidownb_;

    std::vector<std::shared_ptr<const StringSpace>> alphaspaces_;
    std::vector<std::shared_ptr<const StringSpace>> betaspaces_;

    std::vector<std::bitset<nbit__>> stringa_;
    std::vector<std::bitset<nbit__>> stringb_;

    std::vector<std::pair<std::shared_ptr<const StringSpace>, std::shared_ptr<const StringSpace>>> stringpairs_;

    std::vector<int> bit_to_numbers(std::bitset<nbit__> bit) const {
      std::vector<int> out;
      for (int i = 0; i != norb_; ++i) if (bit[i]) out.push_back(i);
      return out;
    }

    std::bitset<nbit__> numbers_to_bit(const std::vector<int>& num) const {
      std::bitset<nbit__> out(0);
      for (auto& i : num) out.set(i);
      return out;
    }

  public:
    RASDeterminants(const int norb1, const int norb2, const int norb3, const int nelea, const int neleb, const int max_holes, const int max_particles, const bool mute = false);
    RASDeterminants(std::array<int, 3> ras, const int nelea, const int neleb, const int max_holes, const int max_particles, const bool mute = false) :
      RASDeterminants(ras[0], ras[1], ras[2], nelea, neleb, max_holes, max_particles, mute) {}

    std::shared_ptr<RASDeterminants> clone(const int nelea, const int neleb) const
      { return std::make_shared<RASDeterminants>(ras_, nelea, neleb, max_holes_, max_particles_, true); }
    std::shared_ptr<RASDeterminants> transpose() const { return this->clone(neleb_, nelea_); }

    static const int Alpha = 0;
    static const int Beta = 1;

    bool operator==(const RASDeterminants& o) const
      { return ( nelea_ == o.nelea_ && neleb_ == o.neleb_ && max_holes_ == o.max_holes_ && max_particles_ == o.max_particles_ && ras_ == o.ras_ ); }

    std::string print_bit(std::bitset<nbit__> bit) const {
      std::string out;
      for (int i = 0; i != norb_; ++i) { out += bit[i] ? "1" : "."; }
      return out;
    }

    std::string print_bit(std::bitset<nbit__> bit1, std::bitset<nbit__> bit2) const {
      std::string out;
      for (int i = 0; i != norb_; ++i) {
        if (bit1[i] && bit2[i]) { out += "2"; }
        else if (bit1[i]) { out += "a"; }
        else if (bit2[i]) { out += "b"; }
        else { out += "."; }
      }
      return out;
    }

    template<int spin>
    int sign(std::bitset<nbit__> bit, int i) const {
      static_assert(nbit__ <= sizeof(unsigned long long)*8, "verify Determinant::sign (and other functions)");
      bit &= (1ull << i) - 1ull;
      return (1 - (((bit.count() + spin*nelea_) & 1 ) << 1));
    }

    int sign(std::bitset<nbit__> bit, int i, int j) const {
      // masking irrelevant bits
      int min, max;
      std::tie(min,max) = std::minmax(i,j);
      bit &= ~((1ull << (min+1)) - 1ull);
      bit &= (1ull << max) - 1ull;
      return 1 - ((bit.count() & 1) << 1);
    }

    const int nholes(const std::bitset<nbit__> bit) const { return ras_[0] - (bit & std::bitset<nbit__>((1ull << ras_[0]) - 1ull)).count(); }
    const int nparticles(const std::bitset<nbit__> bit) const { return (bit & std::bitset<nbit__>(((1ull << ras_[2]) - 1ull) << (ras_[0] + ras_[1]))).count(); }

    const bool allowed(const std::bitset<nbit__> bit) const { return nholes(bit) <= max_holes_ && nparticles(bit) <= max_particles_; }

    const bool allowed(const int nha, const int nhb, const int npa, const int npb) const
      { return ( (nha + nhb) <= max_holes_ && (npa + npb) <= max_particles_ ); }
    const bool allowed(const std::bitset<nbit__> abit, const std::bitset<nbit__> bbit) const
      { return (nholes(abit) + nholes(bbit)) <= max_holes_ && (nparticles(abit) + nparticles(bbit)) <= max_particles_; }
    const bool allowed(const std::shared_ptr<const StringSpace> alpha, const std::shared_ptr<const StringSpace> beta) const
      { return (beta->nholes() + alpha->nholes()) <= max_holes_ && (beta->nparticles() + alpha->nparticles()) <= max_particles_; }


    // These access the global string lists
    const std::bitset<nbit__>& stringa(const size_t i) const { return stringa_[i]; }
    const std::bitset<nbit__>& stringb(const size_t i) const { return stringb_[i]; }
    const std::vector<std::bitset<nbit__>>& stringa() const { return stringa_; }
    const std::vector<std::bitset<nbit__>>& stringb() const { return stringb_; }

    const std::vector<std::pair<std::shared_ptr<const StringSpace>, std::shared_ptr<const StringSpace>>>& stringpairs() const { return stringpairs_; }

    const int nspin() const { return nelea_ - neleb_; }
    const int norb()  const { return norb_; }
    const int nelea() const { return nelea_; }
    const int neleb() const { return neleb_; }
    const std::array<int, 3> ras() const { return ras_; }
    const int ras(const int i) const { return ras_[i]; }

    const int max_holes() const { return max_holes_; }
    const int max_particles() const { return max_particles_; }

    const size_t lena() const { return stringa_.size(); }
    const size_t lenb() const { return stringb_.size(); }
    const size_t size() const { return size_; }
    const int lenholes() const { return lenholes_; }
    const int lenparts() const { return lenparts_; }

    const std::vector<std::vector<RAS::DMap>>& phia() const { return phia_; }
    const std::vector<std::vector<RAS::DMap>>& phib() const { return phib_; }

    const std::vector<RAS::DMap>& phia(const size_t target) const { return phia_[target]; }
    const std::vector<RAS::DMap>& phib(const size_t target) const { return phib_[target]; }

    const std::vector<RAS::DMap>& phia_ij(const size_t ij) const { return phia_ij_[ij]; }
    const std::vector<RAS::DMap>& phib_ij(const size_t ij) const { return phib_ij_[ij]; }

    const std::vector<RAS::DMap>& phiupa(const size_t target) const { return phiupa_[target]; }
    const std::vector<RAS::DMap>& phiupb(const size_t target) const { return phiupb_[target]; }
    const std::vector<RAS::DMap>& phidowna(const size_t target) const { return phidowna_[target]; }
    const std::vector<RAS::DMap>& phidownb(const size_t target) const { return phidownb_[target]; }

    std::shared_ptr<const RASDeterminants> addalpha() const { return addalpha_.lock();}
    std::shared_ptr<const RASDeterminants> remalpha() const { return remalpha_.lock();}
    std::shared_ptr<const RASDeterminants> addbeta() const { return addbeta_.lock();}
    std::shared_ptr<const RASDeterminants> rembeta() const { return rembeta_.lock();}

    std::shared_ptr<RASDeterminants> addalpha() { return addalpha_.lock();}
    std::shared_ptr<RASDeterminants> remalpha() { return remalpha_.lock();}
    std::shared_ptr<RASDeterminants> addbeta() { return addbeta_.lock();}
    std::shared_ptr<RASDeterminants> rembeta() { return rembeta_.lock();}

    template <int spin> void link(std::shared_ptr<RASDeterminants> odet);

    std::vector<std::shared_ptr<const StringSpace>>& stringspacea() { return alphaspaces_; }
    std::vector<std::shared_ptr<const StringSpace>>& stringspaceb() { return betaspaces_; }
    const std::vector<std::shared_ptr<const StringSpace>>& stringspacea() const { return alphaspaces_; }
    const std::vector<std::shared_ptr<const StringSpace>>& stringspaceb() const { return betaspaces_; }

    template <int spin> std::shared_ptr<const StringSpace> space(const int nholes, const int nparticles) const
      { return ( spin == Alpha ? alphaspaces_ : betaspaces_ )[nparticles + nholes * (max_particles_ + 1)]; }
    template <int spin> std::shared_ptr<const StringSpace> space(const std::bitset<nbit__>& bit) const
      { return space<spin>(nholes(bit), nparticles(bit)); }

    template <int spin> const size_t lexical(const std::bitset<nbit__>& bit) const { return space<spin>(bit)->lexical(bit); }

    std::pair<std::vector<std::tuple<std::bitset<nbit__>, std::bitset<nbit__>, int>>, double> spin_adapt(const int spin,
                                                                   const std::bitset<nbit__> alpha, const std::bitset<nbit__> beta) const;

  private:
    template <int spin> void construct_phis_(const std::vector<std::bitset<nbit__>>& strings, std::vector<std::vector<RAS::DMap>>& phi, std::vector<std::vector<RAS::DMap>>& phi_ij);
};

template <int spin>
void RASDeterminants::construct_phis_(const std::vector<std::bitset<nbit__>>& strings, std::vector<std::vector<RAS::DMap>>& phi, std::vector<std::vector<RAS::DMap>>& phi_ij) {

  phi.clear();
  phi.resize( strings.size() );
  for (auto& iphi : phi) iphi.reserve(norb_ * norb_);

  phi_ij.clear();
  phi_ij.resize( (norb_ * (norb_ + 1))/2 );
  for (auto& iphi : phi_ij) iphi.reserve( strings.size() );

  auto iphi = phi.begin();
  size_t tindex = 0;
  for (auto istring = strings.begin(); istring != strings.end(); ++istring, ++iphi, ++tindex) {
    const std::bitset<nbit__> targetbit = *istring;
    for (int j = 0; j < norb_; ++j) {
      if ( !targetbit[j] ) continue;
      std::bitset<nbit__> intermediatebit = targetbit; intermediatebit.reset(j);
      for (int i = 0; i < norb_; ++i) {
        if ( intermediatebit[i] ) continue;
        std::bitset<nbit__> sourcebit = intermediatebit; sourcebit.set(i);
        if ( allowed(sourcebit) ) {
          iphi->emplace_back(lexical<spin>(sourcebit), tindex, j + i * norb_, sign(targetbit, i, j));
          int minij, maxij;
          std::tie(minij, maxij) = std::minmax(i,j);
          phi_ij[minij+((maxij*(maxij+1))>>1)].emplace_back(lexical<spin>(sourcebit), tindex, j + i * norb_, sign(targetbit, i, j));
        }
      }
    }
  }
}

template <int spin>
void RASDeterminants::link(std::shared_ptr<RASDeterminants> odet) {
  std::shared_ptr<RASDeterminants> plusdet;
  std::shared_ptr<RASDeterminants> det;
  if (spin==0) {
    int de = this->nelea() - odet->nelea();
    if (de == 1) std::tie(det, plusdet) = make_pair(odet, shared_from_this());
    else if (de == -1) std::tie(det, plusdet) = make_pair(shared_from_this(), odet);
    else assert(false);
  }
  else {
    int de = this->neleb() - odet->neleb();
    if (de == 1) std::tie(det, plusdet) = make_pair(odet, shared_from_this());
    else if (de == -1) std::tie(det, plusdet) = make_pair(shared_from_this(), odet);
    else assert(false);
  }

  std::vector<std::vector<RAS::DMap>> phiup;
  std::vector<std::vector<RAS::DMap>> phidown;

  phiup.resize(norb_);
  const size_t upsize = ( (spin==0) ? plusdet->lena() : plusdet->lenb() );
  for (auto& iter : phiup) {
    iter.reserve(upsize);
  }

  phidown.resize(norb_);
  const size_t downsize = ( (spin==0) ? det->lena() : det->lenb() );
  for (auto& iter : phidown) {
    iter.reserve(downsize);
  }

  std::vector<std::bitset<nbit__>> stringplus = ( (spin==0) ? plusdet->stringa() : plusdet->stringb() );
  std::vector<std::bitset<nbit__>> string = ( (spin==0) ? det->stringa() : det->stringb() );

  for (auto& istring : string) {
    for (unsigned int i = 0; i != norb_; ++i) {
      if (!(istring)[i]) { // creation
        const unsigned int source = det->lexical<spin>(istring);
        std::bitset<nbit__> nbit = istring; nbit.set(i); // created.
        if (plusdet->allowed(nbit)) {
          const size_t target = plusdet->lexical<spin>(nbit);
          phiup[i].emplace_back(source, target, i, sign<spin>(nbit, i));
        }
      }
    }
  }

  for (auto& istring : stringplus) {
    for (unsigned int i = 0; i!= norb_; ++i) {
      if (istring[i]) { // annihilation
        const unsigned int source = plusdet->lexical<spin>(istring);
        std::bitset<nbit__> nbit = istring; nbit.reset(i); //annihilated.
        if (det->allowed(nbit)) {
          const unsigned int target = det->lexical<spin>(nbit);
          phidown[i].emplace_back(source, target, i, sign<spin>(nbit, i));
        }
      }
    }
  }

  // finally link
  if (spin == 0) {
    plusdet->remalpha_ = det;
    plusdet->phidowna_ = phidown;

    det->addalpha_ = plusdet;
    det->phiupa_ = phiup;
  }
  else {
    plusdet->rembeta_ = det;
    plusdet->phidownb_ = phidown;

    det->addbeta_ = plusdet;
    det->phiupb_ = phiup;
  }
}

}

#endif