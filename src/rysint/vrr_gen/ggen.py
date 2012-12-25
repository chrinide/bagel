#!/usr/bin/python

import math

ss = "\
//\n\
// BAGEL - Parallel electron correlation program.\n\
// Filename: gvrr.cc\n\
// Copyright (C) 2012 Toru Shiozaki\n\
//\n\
// Author: Toru Shiozaki <shiozaki@northwestern.edu>\n\
// Maintainer: Shiozaki group\n\
//\n\
// This file is part of the BAGEL package.\n\
//\n\
// The BAGEL package is free software; you can redistribute it and/or modify\n\
// it under the terms of the GNU Library General Public License as published by\n\
// the Free Software Foundation; either version 2, or (at your option)\n\
// any later version.\n\
//\n\
// The BAGEL package is distributed in the hope that it will be useful,\n\
// but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
// GNU Library General Public License for more details.\n\
//\n\
// You should have received a copy of the GNU Library General Public License\n\
// along with the BAGEL package; see COPYING.  If not, write to\n\
// the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.\n\
//\n\
\n\
#include <src/rysint/gradbatch.h>\n\
#include <src/rysint/_gvrr_drv.h>\n\
#include <src/util/comb.h>\n\
#include <src/util/f77.h>\n\
\n\
using namespace std;\n\
using namespace bagel;\n\
\n\
static const Comb comb;\n\
\n\
\n\
void GradBatch::perform_VRR() {\n\
#ifndef LIBINT_INTERFACE\n\
  const int acsize = size_block_ / primsize_;\n\
  const int a = basisinfo_[0]->angular_number();\n\
  const int b = basisinfo_[1]->angular_number();\n\
  const int c = basisinfo_[2]->angular_number();\n\
  const int d = basisinfo_[3]->angular_number();\n\
\n\
  const int isize = (amax_ + 1) * (cmax_ + 1); \n\
  double* const workx = stack_->get(isize*rank_*3);\n\
  double* const worky = workx + isize*rank_;\n\
  double* const workz = worky + isize*rank_;\n\
\n\
  const int a2 = a+2;\n\
  const int b2 = b+2;\n\
  const int c2 = c+2;\n\
  const int d2 = d+2;\n\
\n\
  double* const transx = stack_->get((amax_+1)*a2*b2);\n\
  double* const transy = stack_->get((amax_+1)*a2*b2);\n\
  double* const transz = stack_->get((amax_+1)*a2*b2);\n\
  double* const trans2x = stack_->get((cmax_+1)*c2*d2);\n\
  double* const trans2y = stack_->get((cmax_+1)*c2*d2);\n\
  double* const trans2z = stack_->get((cmax_+1)*c2*d2);\n\
  fill(transx,  transx +(amax_+1)*a2*b2, 0.0);\n\
  fill(transy,  transy +(amax_+1)*a2*b2, 0.0);\n\
  fill(transz,  transz +(amax_+1)*a2*b2, 0.0);\n\
  fill(trans2x, trans2x+(cmax_+1)*c2*d2, 0.0);\n\
  fill(trans2y, trans2y+(cmax_+1)*c2*d2, 0.0);\n\
  fill(trans2z, trans2z+(cmax_+1)*c2*d2, 0.0);\n\
  // for usual integrals\n\
  for (int ib = 0, k = 0; ib <= b+1; ++ib) {\n\
    for (int ia = 0; ia <= a+1; ++ia, ++k) {\n\
      if (ia == a+1 && ib == b+1) continue;\n\
      for (int i = ia; i <= ia+ib; ++i) {\n\
        transx[i + (amax_+1)*k] = comb.c(ib, ia+ib-i) * pow(AB_[0], ia+ib-i);\n\
        transy[i + (amax_+1)*k] = comb.c(ib, ia+ib-i) * pow(AB_[1], ia+ib-i);\n\
        transz[i + (amax_+1)*k] = comb.c(ib, ia+ib-i) * pow(AB_[2], ia+ib-i);\n\
      }   \n\
    }   \n\
  }\n\
  for (int id = 0, k = 0; id <= d+1; ++id) {\n\
    for (int ic = 0; ic <= c+1; ++ic, ++k) {\n\
      if (ic == c+1 && id == d+1) continue;\n\
      for (int i = ic; i <= ic+id; ++i) {\n\
        trans2x[i + (cmax_+1)*k] = comb.c(id, ic+id-i) * pow(CD_[0], ic+id-i);\n\
        trans2y[i + (cmax_+1)*k] = comb.c(id, ic+id-i) * pow(CD_[1], ic+id-i);\n\
        trans2z[i + (cmax_+1)*k] = comb.c(id, ic+id-i) * pow(CD_[2], ic+id-i);\n\
      }   \n\
    }   \n\
  }\n\
  double* const intermediate = stack_->get(b2*a2*(cmax_+1)*rank_);\n\
  double* const final_x  = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_y  = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_z  = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_xa = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_xb = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_xc = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_ya = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_yb = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_yc = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_za = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_zb = stack_->get(b2*a2*c2*d2*rank_);\n\
  double* const final_zc = stack_->get(b2*a2*c2*d2*rank_);\n";

for a in range(0,7):
 for b in range(0,7):
  if a < b: continue
  for c in range(0,7):
   for d in range(0,7):
    if c < d: continue
    rank = int(math.ceil((a+b+c+d+2)*0.5-0.001))

    if a == 0 and c == 0: 
     ss += "\
  if (a == " + str(a) + " && b == " + str(b) + " && c == " + str(c) + " && d == " + str(d) + ") {\n"
    else:
     ss += "\
  } else if (a == " + str(a) + " && b == " + str(b) + " && c == " + str(c) + " && d == " + str(d) + ") {\n"
    ss += "\
    for (int j = 0; j != screening_size_; ++j) {\n\
      int ii = screening_[j];\n\
      gvrr_driver<" + str(a) + "," + str(b) + "," + str(c) + "," +  str(d) + "," + str(rank) + ">(data_+ii*acsize, roots_+ii*rank_, weights_+ii*rank_, coeff_[ii],\n\
                    basisinfo_[0]->position(), basisinfo_[1]->position(), basisinfo_[2]->position(), basisinfo_[3]->position(),\n\
                    p_+ii*3, q_+ii*3, xp_[ii], xq_[ii], size_block_,\n\
                    exponents_.get()+ii*4, transx, transy, transz, trans2x, trans2y, trans2z, intermediate,\n\
                    final_x, final_y, final_z, final_xa, final_xb, final_xc, final_ya, final_yb, final_yc, final_za, final_zb, final_zc, workx, worky, workz);\n\
    }\n"
ss += "\
  }\n\
  stack_->release(b2*a2*c2*d2*rank_, final_zc);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_zb);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_za);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_yc);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_yb);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_ya);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_xc);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_xb);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_xa);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_z);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_y);\n\
  stack_->release(b2*a2*c2*d2*rank_, final_x);\n\
\n\
  stack_->release(b2*a2*(cmax_+1)*rank_, intermediate);\n\
\n\
  stack_->release((cmax_+1)*c2*d2, trans2z);\n\
  stack_->release((cmax_+1)*c2*d2, trans2y);\n\
  stack_->release((cmax_+1)*c2*d2, trans2x);\n\
\n\
  stack_->release((amax_+1)*a2*b2, transz);\n\
  stack_->release((amax_+1)*a2*b2, transy);\n\
  stack_->release((amax_+1)*a2*b2, transx);\n\
  stack_->release(rank_*isize*3, workx);\n\
\n\
#endif\n\
}"


print ss;
