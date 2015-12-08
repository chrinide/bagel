//
// BAGEL - Parallel electron correlation program.
// Filename: RelMRCI_normqq.cc
// Copyright (C) 2014 Shiozaki group
//
// Author: Shiozaki group <shiozaki@northwestern.edu>
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

#include <bagel_config.h>
#ifdef COMPILE_SMITH


#include <src/smith/RelMRCI.h>
#include <src/smith/RelMRCI_tasks.h>

using namespace std;
using namespace bagel;
using namespace bagel::SMITH;

shared_ptr<Queue> RelMRCI::RelMRCI::make_normq(const bool reset, const bool diagonal) {

  auto normq = make_shared<Queue>();
  auto task748 = make_shared<Task748>(n, reset);
  normq->add_task(task748);

  auto I1335 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{closed_, closed_, active_, active_});
  auto task749 = make_shared<Task749>(n, I1335);
  task749->add_dep(task748);
  normq->add_task(task749);

  auto task750 = make_shared<Task750>(I1335, Gamma0_(), t2);
  task749->add_dep(task750);
  task750->add_dep(task748);
  normq->add_task(task750);

  auto I1337 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{closed_, active_, active_, active_});
  auto task751 = make_shared<Task751>(n, I1337);
  task751->add_dep(task748);
  normq->add_task(task751);

  auto task752 = make_shared<Task752>(I1337, Gamma4_(), t2);
  task751->add_dep(task752);
  task752->add_dep(task748);
  normq->add_task(task752);

  auto I1339 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{closed_, virt_, closed_, active_});
  auto task753 = make_shared<Task753>(n, I1339);
  task753->add_dep(task748);
  normq->add_task(task753);

  auto I1340 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{closed_, virt_, closed_, active_});
  auto task754 = make_shared<Task754>(I1339, Gamma11_(), I1340);
  task753->add_dep(task754);
  task754->add_dep(task748);
  normq->add_task(task754);

  auto task755 = make_shared<Task755>(I1340, t2);
  task754->add_dep(task755);
  task755->add_dep(task748);
  normq->add_task(task755);

  auto I1343 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{closed_, virt_, active_, active_});
  auto task756 = make_shared<Task756>(n, I1343);
  task756->add_dep(task748);
  normq->add_task(task756);

  auto task757 = make_shared<Task757>(I1343, Gamma24_(), t2);
  task756->add_dep(task757);
  task757->add_dep(task748);
  normq->add_task(task757);

  auto I1345 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{virt_, active_, active_, active_});
  auto task758 = make_shared<Task758>(n, I1345);
  task758->add_dep(task748);
  normq->add_task(task758);

  auto task759 = make_shared<Task759>(I1345, Gamma32_(), t2);
  task758->add_dep(task759);
  task759->add_dep(task748);
  normq->add_task(task759);

  shared_ptr<TATensor<std::complex<double>,4>> I1347;
  if (diagonal) {
    I1347 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{closed_, virt_, closed_, virt_});
  }
  shared_ptr<Task760> task760;
  if (diagonal) {
    task760 = make_shared<Task760>(n, I1347);
    task760->add_dep(task748);
    normq->add_task(task760);
  }

  shared_ptr<Task761> task761;
  if (diagonal) {
    task761 = make_shared<Task761>(I1347, t2);
    task760->add_dep(task761);
    task761->add_dep(task748);
    normq->add_task(task761);
  }

  auto I1349 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{virt_, closed_, virt_, active_});
  auto task762 = make_shared<Task762>(n, I1349);
  task762->add_dep(task748);
  normq->add_task(task762);

  auto I1350 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{active_, virt_, closed_, virt_});
  auto task763 = make_shared<Task763>(I1349, Gamma27_(), I1350);
  task762->add_dep(task763);
  task763->add_dep(task748);
  normq->add_task(task763);

  auto task764 = make_shared<Task764>(I1350, t2);
  task763->add_dep(task764);
  task764->add_dep(task748);
  normq->add_task(task764);

  auto I1353 = make_shared<TATensor<std::complex<double>,4>>(std::vector<IndexRange>{virt_, virt_, active_, active_});
  auto task765 = make_shared<Task765>(n, I1353);
  task765->add_dep(task748);
  normq->add_task(task765);

  auto task766 = make_shared<Task766>(I1353, Gamma33_(), t2);
  task765->add_dep(task766);
  task766->add_dep(task748);
  normq->add_task(task766);

  return normq;
}


#endif
