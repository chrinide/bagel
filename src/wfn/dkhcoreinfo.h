//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: dkhcoreinfo.h
// Copyright (C) 2017 Toru Shiozaki
//
// Author: Nils Strand <nilsstrand2022@u.northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//


#ifndef __SRC_WFN_DKHCOREINFO_H
#define __SRC_WFN_DKHCOREINFO_H

#include <src/mat1e/grad/gkinetic.h>
#include <src/mat1e/grad/gnai.h>
#include <src/molecule/molecule.h>
#include <src/util/math/xyzfile.h>

namespace bagel {

class DKHcoreInfo {

  private:
    std::shared_ptr<const GKinetic> tgrad_;
    std::shared_ptr<const GNAI> vgrad_;
    std::shared_ptr<const Matrix> transfer_;
    bool dkh2;

  public:
    DKHcoreInfo() { }
    DKHcoreInfo(const std::shared_ptr<const Molecule>, const int);
    ~DKHcoreInfo() { }

    std::shared_ptr<GradFile> compute_t(const std::array<std::shared_ptr<const Shell>,2>&, const std::array<int,4>&, const std::array<int,4>&, const std::shared_ptr<const Matrix>);
    std::shared_ptr<GradFile> compute_v(const std::array<std::shared_ptr<const Shell>,2>&, const std::array<int,4>&, const std::array<int,4>&, const std::shared_ptr<const Matrix>);
    std::shared_ptr<GradFile> compute_v2(const std::array<std::shared_ptr<const Shell>,2>&, const std::array<int,4>&, const std::array<int,4>&, const std::shared_ptr<const Matrix>);

    std::shared_ptr<const GKinetic> tgrad() const { return tgrad_; }
    std::shared_ptr<const GNAI> vgrad() const { return vgrad_; }
    std::shared_ptr<const Matrix> transfer() const { return transfer_; }
};

}

#endif
