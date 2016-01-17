//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: _sphusp_5.cc
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

vector<double> SphUSPList::sphusp_5(const int m) {

  vector<double> c;
  constexpr double coeff[231] = {   0.000000000000000e+00,   3.281910284200851e+00,   0.000000000000000e+00,  -6.563820568401701e+00,   0.000000000000000e+00,
   6.563820568401701e-01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   8.302649259524166e+00,   0.000000000000000e+00,  -8.302649259524166e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,  -1.467714898305751e+00,   0.000000000000000e+00,  -9.784765988705008e-01,   0.000000000000000e+00,
   4.892382994352504e-01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   1.174171918644601e+01,   0.000000000000000e+00,  -3.913906395482003e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,  -4.793536784973324e+00,   0.000000000000000e+00,  -4.793536784973324e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   9.587073569946648e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   4.529466511956969e-01,   0.000000000000000e+00,   9.058933023913939e-01,   0.000000000000000e+00,
   4.529466511956969e-01,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,  -5.435359814348364e+00,   0.000000000000000e+00,  -5.435359814348364e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   3.623573209565575e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   1.754254836801354e+00,   0.000000000000000e+00,   3.508509673602708e+00,   0.000000000000000e+00,
   1.754254836801354e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
  -4.678012898136943e+00,   0.000000000000000e+00,  -4.678012898136943e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   9.356025796273887e-01,   4.529466511956969e-01,   0.000000000000000e+00,   9.058933023913939e-01,   0.000000000000000e+00,   4.529466511956969e-01,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -5.435359814348364e+00,   0.000000000000000e+00,  -5.435359814348364e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   3.623573209565575e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -2.396768392486662e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   2.396768392486662e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   4.793536784973324e+00,   0.000000000000000e+00,  -4.793536784973324e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,  -4.892382994352504e-01,   0.000000000000000e+00,   9.784765988705008e-01,   0.000000000000000e+00,   1.467714898305751e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   3.913906395482003e+00,   0.000000000000000e+00,  -1.174171918644601e+01,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   2.075662314881042e+00,   0.000000000000000e+00,  -1.245397388928625e+01,   0.000000000000000e+00,
   2.075662314881042e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   6.563820568401701e-01,   0.000000000000000e+00,  -6.563820568401701e+00,   0.000000000000000e+00,   3.281910284200851e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,   0.000000000000000e+00,
   0.000000000000000e+00};

  assert(abs(m) <= 5);
  const int size_c = (5 + 1) * (5 + 2) / 2;
  const int mu = m + 5;
  const int i0 = mu * size_c;
  for (int i = i0; i != i0 + size_c; ++i) c.push_back(coeff[i]);
  return c;

}
