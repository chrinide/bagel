//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: _sphusp_9.cc
// Copyright (C) 2014 Toru Shiozaki
//
// Author: Hai-Anh Le <anh@u.northwestern.edu>
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

#include <algorithm>
#include <cassert>
#include <src/integral/ecp/sphusplist.h>

using namespace std;
using namespace bagel;

vector<double> SphUSPList::sphusp_9(const int m) {

  vector<double> c;
  constexpr double coeff[1045] = {   0.000000000000000e+00,   6.740108566678695e+00,   0.000000000000000e+00,  -6.290767995566782e+01,   0.000000000000000e+00,
   9.436151993350174e+01,   0.000000000000000e+00,  -2.696043426671478e+01,   0.000000000000000e+00,   7.489009518531884e-01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   2.541854119163758e+01,   0.000000000000000e+00,  -1.779297883414631e+02,   0.000000000000000e+00,
   1.779297883414631e+02,   0.000000000000000e+00,  -2.541854119163758e+01,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -3.814338369408372e+00,   0.000000000000000e+00,   1.525735347763349e+01,   0.000000000000000e+00,
   7.628676738816744e+00,   0.000000000000000e+00,  -1.089810962688106e+01,   0.000000000000000e+00,   5.449054813440531e-01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   6.102941391053395e+01,   0.000000000000000e+00,  -3.051470695526697e+02,   0.000000000000000e+00,   1.830882417316019e+02,
   0.000000000000000e+00,  -8.718487701504850e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -2.265129549625621e+01,   0.000000000000000e+00,   5.285302282459782e+01,   0.000000000000000e+00,
   5.285302282459782e+01,   0.000000000000000e+00,  -2.265129549625621e+01,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   1.057060456491956e+02,   0.000000000000000e+00,
  -3.523534854973187e+02,   0.000000000000000e+00,   1.057060456491956e+02,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   2.436891395195093e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -6.823295906546259e+00,   0.000000000000000e+00,  -3.899026232312148e+00,   0.000000000000000e+00,   4.873782790390185e-01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -6.823295906546259e+01,   0.000000000000000e+00,   6.823295906546259e+01,   0.000000000000000e+00,   1.228193263178327e+02,
   0.000000000000000e+00,  -1.364659181309252e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   1.364659181309252e+02,   0.000000000000000e+00,  -2.729318362618504e+02,   0.000000000000000e+00,   2.729318362618504e+01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   1.631079695491670e+01,   0.000000000000000e+00,   1.631079695491670e+01,   0.000000000000000e+00,
  -1.631079695491670e+01,   0.000000000000000e+00,  -1.631079695491670e+01,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,  -1.304863756393336e+02,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   1.304863756393336e+02,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   1.304863756393336e+02,   0.000000000000000e+00,  -1.304863756393336e+02,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -1.385125560048583e+00,   0.000000000000000e+00,  -3.693668160129556e+00,   0.000000000000000e+00,
  -2.770251120097167e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   4.617085200161944e-01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   4.986452016174900e+01,   0.000000000000000e+00,   8.310753360291500e+01,   0.000000000000000e+00,   1.662150672058300e+01,
   0.000000000000000e+00,  -1.662150672058300e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -1.662150672058300e+02,   0.000000000000000e+00,  -1.108100448038867e+02,   0.000000000000000e+00,   5.540502240194333e+01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   8.864803584310934e+01,   0.000000000000000e+00,  -2.954934528103644e+01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -8.463256967920978e+00,   0.000000000000000e+00,  -2.538977090376294e+01,   0.000000000000000e+00,
  -2.538977090376294e+01,   0.000000000000000e+00,  -8.463256967920978e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   8.463256967920978e+01,   0.000000000000000e+00,
   1.692651393584196e+02,   0.000000000000000e+00,   8.463256967920978e+01,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -1.354121114867357e+02,   0.000000000000000e+00,  -1.354121114867357e+02,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   3.868917471049590e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   4.510931120655911e-01,   0.000000000000000e+00,   1.804372448262364e+00,   0.000000000000000e+00,
   2.706558672393546e+00,   0.000000000000000e+00,   1.804372448262364e+00,   0.000000000000000e+00,   4.510931120655911e-01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -1.804372448262364e+01,   0.000000000000000e+00,  -5.413117344787092e+01,   0.000000000000000e+00,  -5.413117344787092e+01,
   0.000000000000000e+00,  -1.804372448262364e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   7.217489793049457e+01,   0.000000000000000e+00,   1.443497958609891e+02,   0.000000000000000e+00,   7.217489793049457e+01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -5.773991834439565e+01,   0.000000000000000e+00,  -5.773991834439565e+01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   8.248559763485094e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   3.026024588281776e+00,   0.000000000000000e+00,   1.210409835312710e+01,   0.000000000000000e+00,   1.815614752969066e+01,
   0.000000000000000e+00,   1.210409835312710e+01,   0.000000000000000e+00,   3.026024588281776e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,  -3.227759560833894e+01,   0.000000000000000e+00,  -9.683278682501684e+01,
   0.000000000000000e+00,  -9.683278682501684e+01,   0.000000000000000e+00,  -3.227759560833894e+01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   5.809967209501010e+01,   0.000000000000000e+00,   1.161993441900202e+02,   0.000000000000000e+00,   5.809967209501010e+01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,  -2.213320841714670e+01,
   0.000000000000000e+00,  -2.213320841714670e+01,   0.000000000000000e+00,   0.000000000000000e+00,   1.229622689841483e+00,
   4.510931120655911e-01,   0.000000000000000e+00,   1.804372448262364e+00,   0.000000000000000e+00,   2.706558672393546e+00,
   0.000000000000000e+00,   1.804372448262364e+00,   0.000000000000000e+00,   4.510931120655911e-01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,  -1.804372448262364e+01,
   0.000000000000000e+00,  -5.413117344787092e+01,   0.000000000000000e+00,  -5.413117344787092e+01,   0.000000000000000e+00,
  -1.804372448262364e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   7.217489793049457e+01,
   0.000000000000000e+00,   1.443497958609891e+02,   0.000000000000000e+00,   7.217489793049457e+01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -5.773991834439565e+01,   0.000000000000000e+00,  -5.773991834439565e+01,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   8.248559763485094e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -4.231628483960489e+00,   0.000000000000000e+00,  -8.463256967920978e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   8.463256967920978e+00,   0.000000000000000e+00,   4.231628483960489e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   4.231628483960489e+01,   0.000000000000000e+00,   4.231628483960489e+01,
   0.000000000000000e+00,  -4.231628483960489e+01,   0.000000000000000e+00,  -4.231628483960489e+01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -6.770605574336783e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   6.770605574336783e+01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   1.934458735524795e+01,
   0.000000000000000e+00,  -1.934458735524795e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -4.617085200161944e-01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   2.770251120097167e+00,
   0.000000000000000e+00,   3.693668160129556e+00,   0.000000000000000e+00,   1.385125560048583e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   1.662150672058300e+01,
   0.000000000000000e+00,  -1.662150672058300e+01,   0.000000000000000e+00,  -8.310753360291500e+01,   0.000000000000000e+00,
  -4.986452016174900e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,  -5.540502240194333e+01,
   0.000000000000000e+00,   1.108100448038867e+02,   0.000000000000000e+00,   1.662150672058300e+02,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   2.954934528103644e+01,   0.000000000000000e+00,  -8.864803584310934e+01,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   4.077699238729174e+00,   0.000000000000000e+00,  -1.631079695491670e+01,   0.000000000000000e+00,  -4.077699238729174e+01,
   0.000000000000000e+00,  -1.631079695491670e+01,   0.000000000000000e+00,   4.077699238729174e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,  -3.262159390983339e+01,   0.000000000000000e+00,   1.631079695491670e+02,
   0.000000000000000e+00,   1.631079695491670e+02,   0.000000000000000e+00,  -3.262159390983339e+01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   3.262159390983339e+01,   0.000000000000000e+00,  -1.957295634590004e+02,   0.000000000000000e+00,   3.262159390983339e+01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   4.873782790390185e-01,   0.000000000000000e+00,  -3.899026232312148e+00,   0.000000000000000e+00,  -6.823295906546259e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   2.436891395195093e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,  -1.364659181309252e+01,
   0.000000000000000e+00,   1.228193263178327e+02,   0.000000000000000e+00,   6.823295906546259e+01,   0.000000000000000e+00,
  -6.823295906546259e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   2.729318362618504e+01,
   0.000000000000000e+00,  -2.729318362618504e+02,   0.000000000000000e+00,   1.364659181309252e+02,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -3.775215916042701e+00,   0.000000000000000e+00,   5.285302282459782e+01,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -5.285302282459782e+01,   0.000000000000000e+00,   3.775215916042701e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   1.761767427486594e+01,   0.000000000000000e+00,  -2.642651141229891e+02,
   0.000000000000000e+00,   2.642651141229891e+02,   0.000000000000000e+00,  -1.761767427486594e+01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -5.449054813440531e-01,   0.000000000000000e+00,   1.089810962688106e+01,   0.000000000000000e+00,  -7.628676738816744e+00,
   0.000000000000000e+00,  -1.525735347763349e+01,   0.000000000000000e+00,   3.814338369408372e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   8.718487701504850e+00,
   0.000000000000000e+00,  -1.830882417316019e+02,   0.000000000000000e+00,   3.051470695526697e+02,   0.000000000000000e+00,
  -6.102941391053395e+01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   3.177317648954698e+00,   0.000000000000000e+00,  -8.896489417073154e+01,   0.000000000000000e+00,   2.224122354268289e+02,
   0.000000000000000e+00,  -8.896489417073154e+01,   0.000000000000000e+00,   3.177317648954698e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   7.489009518531884e-01,   0.000000000000000e+00,  -2.696043426671478e+01,   0.000000000000000e+00,   9.436151993350174e+01,
   0.000000000000000e+00,  -6.290767995566782e+01,   0.000000000000000e+00,   6.740108566678695e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00
};

  assert(abs(m) <= 9);
  const int size_c = (9 + 1) * (9 + 2) / 2;
  const int mu = m + 9;
  const int i0 = mu * size_c;
  for (int i = i0; i != i0 + size_c; ++i) c.push_back(coeff[i]);
  return c;

}
