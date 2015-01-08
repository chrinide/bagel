//
// BAGEL - Parallel electron correlation program.
// Filename: multipolebatch_base.h
// Copyright (C) 2014 Toru Shiozaki
//
// Author: Hai-Anh Le <anh@u.northwestern.edu>
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


#ifndef __SRC_PERIODIC_MULTIPOLEBATCH_BASE_H
#define __SRC_PERIODIC_MULTIPOLEBATCH_BASE_H

#include <src/parallel/resources.h>
#include <src/molecule/atom.h>
#include <src/integral/os/osintegral.h>
#include <src/periodic/multipole.h>

namespace bagel {

class MultipoleBatch_base : public OSIntegral<std::complex<double>> {
  protected:
    std::array<std::shared_ptr<const Shell>,2> basisinfo_;
    std::array<double, 3> centre_;
    int lmax_;

    int asize_, asize_final_, asize_final_sph_, amax_;

    int num_multipoles_;
    std::complex<double>* multipole_;

    std::complex<double>* multipole_buff_;

    void init();
    void allocate_arrays(const size_t ps);
    void compute_ss(const double thresh);
    int nblocks() const override { return num_multipoles_; }
    int nrank() const override { return 0; }

  public:
    MultipoleBatch_base(const std::array<std::shared_ptr<const Shell>,2>& shells, const std::array<double, 3> centre,
                        const int lmax = ANG_HRR_END, std::shared_ptr<StackMem> stack = nullptr);
    ~MultipoleBatch_base() { }

    std::array<double, 3> centre() const { return centre_; }

    virtual void compute() = 0;
};

}

#endif
