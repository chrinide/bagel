//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: MRCI_tasks8.cc
// Copyright (C) 2014 Shiozaki group
//
// Author: Shiozaki group <shiozaki@northwestern.edu>
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

#include <bagel_config.h>
#ifdef COMPILE_SMITH

#include <src/smith/mrci/MRCI_tasks8.h>

using namespace std;
using namespace bagel;
using namespace bagel::SMITH;
using namespace bagel::SMITH::MRCI;

void Task350::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("x2, a1, c2, x3") += (*ta1_)("c4, a3, c2, x3") * (*ta2_)("x2, c4, a3, a1");
}

void Task351::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("x2, a1, c2, x3") += (*ta1_)("c3, a4, c2, x3") * (*ta2_)("x2, a1, a4, c3") * (-2);
}

void Task352::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("x2, a1, c2, x3") += (*ta1_)("c2, a4, c3, x3") * (*ta2_)("x2, a1, a4, c3");
}

void Task353::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("x2, a1, c2, x3") += (*ta1_)("c2, a4, c3, a1") * (*ta2_)("a4, x3, x2, c3");
}

void Task354::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("x2, x3, x1, x0") * (*ta2_)("x2, c2, a1, x3");
}

void Task355::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("x2, c2, a1, x3") += (*ta1_)("c2, a1, c3, x3") * (*ta2_)("x2, c3") * (-1);
}

void Task356::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("x2, c2, a1, x3") += (*ta1_)("c3, a1, c4, x3") * (*ta2_)("x2, c4, c2, c3");
}

void Task357::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("x2, c2, a1, x3") += (*ta1_)("c2, a3, c4, x3") * (*ta2_)("x2, c4, a3, a1") * (-1);
}

void Task358::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("x2, c2, a1, x3") += (*ta1_)("c2, a1, c3, a4") * (*ta2_)("a4, x3, x2, c3") * (-1);
}

void Task359::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("x3, x0, x1, x2") * (*ta2_)("c2, x3, a1, x2");
}

void Task360::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x3, a1, x2") += (*ta1_)("x3, a1, c3, x2") * (*ta2_)("c2, c3") * (-1);
}

void Task361::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x3, a1, x2") += (*ta1_)("x3, a3, c2, x2") * (*ta2_)("a3, a1");
}

void Task362::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x3, a1, x2") += (*ta1_)("x3, a1, c2, a3") * (*ta2_)("a3, x2");
}

void Task363::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x3, a1, x2") += (*ta1_)("x3, a3, c4, x2") * (*ta2_)("c2, c4, a3, a1") * (-1);
}

void Task364::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x3, a1, x2") += (*ta1_)("c2, a3, c4, a1") * (*ta2_)("x3, c4, a3, x2") * (-1);
}

void Task365::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x3, a1, x2") += (*ta1_)("x3, a1, c3, a4") * (*ta2_)("a4, x2, c2, c3");
}

void Task366::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("a4, x2, c2, c3") += (*ta1_)("a4, x2, c2, c3") * (-1)
     + (*ta1_)("c2, x2, a4, c3") * 2;
}

void Task367::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x3, a1, x2") += (*ta1_)("x3, a4, c3, a1") * (*ta2_)("c2, x2, a4, c3") * (-1);
}

void Task368::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x3, a1, x2") += (*ta1_)("x3, a3, c2, a4") * (*ta2_)("a4, x2, a3, a1");
}

void Task369::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("x3, x2, x1, x0") * (*ta2_)("c2, a1, x3, x2");
}

void Task370::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("c3, a1, x3, x2") * (*ta2_)("c2, c3");
}

void Task371::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("c2, a3, x3, x2") * (*ta2_)("a3, a1") * (-1);
}

void Task372::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("x3, a3, c2, a1") * (*ta2_)("a3, x2") * (-1);
}

void Task373::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("x3, a4, c3, x2") * (*ta2_)("c2, a1, a4, c3");
}

void Task374::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("c4, a3, x3, x2") * (*ta2_)("c2, c4, a3, a1");
}

void Task375::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("c3, a4, x3, x2") * (*ta2_)("c2, a1, a4, c3") * (-2);
}

void Task376::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("c2, a4, c3, a1") * (*ta2_)("a4, c3, x3, x2");
}

void Task377::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("a4, c3, x3, x2") += (*ta1_)("a4, c3, x3, x2")
     + (*ta1_)("x3, x2, a4, c3");
}

void Task378::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("c2, a1, c3, a4") * (*ta2_)("a4, c3, x3, x2");
}

void Task379::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("a4, c3, x3, x2") += (*ta1_)("a4, c3, x3, x2") * (-2)
     + (*ta1_)("x3, x2, a4, c3") * (-2);
}

void Task380::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("c2, a1, c4, a3") * (*ta2_)("x3, c4, a3, x2");
}

void Task381::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("x3, a4, c3, a1") * (*ta2_)("a4, x2, c2, c3");
}

void Task382::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1, x3, x2") += (*ta1_)("x3, a4, c2, a3") * (*ta2_)("a4, x2, a3, a1") * (-1);
}

void Task383::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("c2, x2") * (*ta2_)("a1, x0, x1, x2");
}

void Task384::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("a1, x0, x1, x2") += (*ta1_)("x5, x0, x4, x3, x1, x2") * (*ta2_)("x5, a1, x4, x3");
}

void Task385::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("x1, x0") * (*ta2_)("c2, a1");
}

void Task386::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1") += (*ta1_)("c2, a4, c3, a1") * (*ta2_)("a4, c3") * 2;
}

void Task387::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1") += (*ta1_)("c2, a1, c3, a4") * (*ta2_)("a4, c3") * (-4);
}

void Task388::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1") += (*ta1_)("c3, a4, c5, a1") * (*ta2_)("c2, c5, a4, c3") * 4;
}

void Task389::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1") += (*ta1_)("c3, a1, c5, a4") * (*ta2_)("c2, c5, a4, c3") * (-2);
}

void Task390::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1") += (*ta1_)("c2, a5, c3, a4") * (*ta2_)("a5, a1, a4, c3") * (-4);
}

void Task391::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, a1") += (*ta1_)("c2, a4, c3, a5") * (*ta2_)("a5, a1, a4, c3") * 2;
}

void Task392::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("x3, a1, x2, c3") * (*ta2_)("c2, c3, x1, x2, x3, x0");
}

void Task393::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("c2, c3, x1, x2, x3, x0") += (*ta1_)("x1, x5, x2, x4, x3, x0") * (*ta2_)("c2, x5, c3, x4") * 2;
}

void Task394::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("x4, a1, x3, x2") * (*ta2_)("c2, x1, x4, x0, x3, x2");
}

void Task395::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("c2, x1, x4, x0, x3, x2") += (*ta1_)("x7, x6, x1, x5, x4, x0, x3, x2") * (*ta2_)("x7, x6, c2, x5") * (-0.5);
}

void Task396::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("x4, x3, x2, a1") * (*ta2_)("c2, x1, x4, x3, x2, x0");
}

void Task397::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("c2, x1, x4, x3, x2, x0") += (*ta1_)("x7, x6, x1, x5, x4, x3, x2, x0") * (*ta2_)("x7, x6, c2, x5") * (-0.5);
}

void Task398::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  (*ta0_)("c2, x1, x0, a1") += (*ta1_)("x2, c3, c2, a1") * (*ta2_)("c3, x2, x1, x0");
}

void Task399::compute_() {
  if (!ta0_->initialized())
    ta0_->fill_local(0.0);
  ta1_->init();
  (*ta0_)("c3, x2, x1, x0") += (*ta1_)("x5, x4, x2, x3, x1, x0") * (*ta2_)("x5, x4, c3, x3") * (-1);
}

#endif
