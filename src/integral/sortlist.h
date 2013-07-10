//
// BAGEL - Parallel electron correlation program.
// Filename: sortlist.h
// Copyright (C) 2009 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and\/or modify
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

//
// stand alone class for HRR functions.
// can be called from outside through sortfunc_call.
//

#ifndef __SRC_RYSINT_SORTLIST_H
#define __SRC_RYSINT_SORTLIST_H

#include <functional>
#include <src/util/constants.h>

namespace bagel {

struct SortList {
  SortList(const bool);
  ~SortList();

  static void sort_indices_00(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_01(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_02(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_03(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_04(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_05(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_06(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_11(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_12(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_13(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_14(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_15(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_16(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_22(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_23(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_24(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_25(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_26(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_33(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_34(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_35(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_36(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_44(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_45(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_46(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_55(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_56(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_66(double*, const double*, const int, const int, const int, const bool);

  static void sort_indices_00_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_01_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_02_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_03_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_04_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_05_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_06_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_11_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_12_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_13_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_14_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_15_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_16_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_22_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_23_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_24_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_25_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_26_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_33_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_34_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_35_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_36_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_44_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_45_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_46_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_55_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_56_sph(double*, const double*, const int, const int, const int, const bool);
  static void sort_indices_66_sph(double*, const double*, const int, const int, const int, const bool);

  void sortfunc_call(const unsigned int i, double* a1, const double* a2, const int a3, const int a4, const int a5, const bool a6) const {
    return (sortfunc[i])(a1, a2, a3, a4, a5, a6);
  };

  std::function<void (double*, const double*, const int, const int, const int, const bool)> sortfunc[ANG_HRR_END * ANG_HRR_END];
};

}

#endif