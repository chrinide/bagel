//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: RelCASPT2_gamma.cc
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

#include <src/smith/relcaspt2/RelCASPT2.h>
#include <src/smith/relcaspt2/RelCASPT2_tasks.h>

using namespace std;
using namespace bagel;
using namespace bagel::SMITH;
using namespace bagel::SMITH::RelCASPT2;

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma0_() {
  auto Gamma0 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma0 = Gamma0->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task0 = make_shared<Task0>(array<shared_ptr<Tensor>,6>{{Gamma0, make_shared<Tensor>(*rdm0_), make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_), make_shared<Tensor>(*f1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma0, Gamma0, task0);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma92_() {
  auto Gamma92 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma92 = Gamma92->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task1 = make_shared<Task1>(array<shared_ptr<Tensor>,4>{{Gamma92, make_shared<Tensor>(*rdm0_), make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma92, Gamma92, task1);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma2_() {
  auto Gamma2 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma2 = Gamma2->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task2 = make_shared<Task2>(array<shared_ptr<Tensor>,4>{{Gamma2, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma2, Gamma2, task2);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma3_() {
  auto Gamma3 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma3 = Gamma3->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task3 = make_shared<Task3>(array<shared_ptr<Tensor>,4>{{Gamma3, make_shared<Tensor>(*rdm0_), make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma3, Gamma3, task3);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma4_() {
  auto Gamma4 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma4 = Gamma4->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task4 = make_shared<Task4>(array<shared_ptr<Tensor>,4>{{Gamma4, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma4, Gamma4, task4);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma5_() {
  auto Gamma5 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma5 = Gamma5->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task5 = make_shared<Task5>(array<shared_ptr<Tensor>,6>{{Gamma5, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_), make_shared<Tensor>(*rdm4_), make_shared<Tensor>(*f1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma5, Gamma5, task5);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma6_() {
  auto Gamma6 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma6 = Gamma6->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task6 = make_shared<Task6>(array<shared_ptr<Tensor>,4>{{Gamma6, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma6, Gamma6, task6);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma7_() {
  auto Gamma7 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma7 = Gamma7->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task7 = make_shared<Task7>(array<shared_ptr<Tensor>,3>{{Gamma7, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma7, Gamma7, task7);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma9_() {
  auto Gamma9 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma9 = Gamma9->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task8 = make_shared<Task8>(array<shared_ptr<Tensor>,4>{{Gamma9, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma9, Gamma9, task8);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma12_() {
  auto Gamma12 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma12 = Gamma12->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task9 = make_shared<Task9>(array<shared_ptr<Tensor>,3>{{Gamma12, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma12, Gamma12, task9);
}

shared_ptr<FutureTATensor<std::complex<double>,2>> RelCASPT2::RelCASPT2::Gamma14_() {
  auto Gamma14 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_});
  auto TAGamma14 = Gamma14->tiledarray<2>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task10 = make_shared<Task10>(array<shared_ptr<Tensor>,5>{{Gamma14, make_shared<Tensor>(*rdm0_), make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*f1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,2>>(*TAGamma14, Gamma14, task10);
}

shared_ptr<FutureTATensor<std::complex<double>,2>> RelCASPT2::RelCASPT2::Gamma16_() {
  auto Gamma16 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_});
  auto TAGamma16 = Gamma16->tiledarray<2>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task11 = make_shared<Task11>(array<shared_ptr<Tensor>,3>{{Gamma16, make_shared<Tensor>(*rdm0_), make_shared<Tensor>(*rdm1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,2>>(*TAGamma16, Gamma16, task11);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma22_() {
  auto Gamma22 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma22 = Gamma22->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task12 = make_shared<Task12>(array<shared_ptr<Tensor>,3>{{Gamma22, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma22, Gamma22, task12);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma28_() {
  auto Gamma28 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma28 = Gamma28->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task13 = make_shared<Task13>(array<shared_ptr<Tensor>,4>{{Gamma28, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma28, Gamma28, task13);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma29_() {
  auto Gamma29 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma29 = Gamma29->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task14 = make_shared<Task14>(array<shared_ptr<Tensor>,3>{{Gamma29, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma29, Gamma29, task14);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma31_() {
  auto Gamma31 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma31 = Gamma31->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task15 = make_shared<Task15>(array<shared_ptr<Tensor>,5>{{Gamma31, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_), make_shared<Tensor>(*f1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma31, Gamma31, task15);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma32_() {
  auto Gamma32 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma32 = Gamma32->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task16 = make_shared<Task16>(array<shared_ptr<Tensor>,3>{{Gamma32, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma32, Gamma32, task16);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma34_() {
  auto Gamma34 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma34 = Gamma34->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task17 = make_shared<Task17>(array<shared_ptr<Tensor>,5>{{Gamma34, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_), make_shared<Tensor>(*f1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma34, Gamma34, task17);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma35_() {
  auto Gamma35 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma35 = Gamma35->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task18 = make_shared<Task18>(array<shared_ptr<Tensor>,3>{{Gamma35, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma35, Gamma35, task18);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma37_() {
  auto Gamma37 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma37 = Gamma37->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task19 = make_shared<Task19>(array<shared_ptr<Tensor>,3>{{Gamma37, make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma37, Gamma37, task19);
}

shared_ptr<FutureTATensor<std::complex<double>,2>> RelCASPT2::RelCASPT2::Gamma38_() {
  auto Gamma38 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_});
  auto TAGamma38 = Gamma38->tiledarray<2>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task20 = make_shared<Task20>(array<shared_ptr<Tensor>,2>{{Gamma38, make_shared<Tensor>(*rdm1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,2>>(*TAGamma38, Gamma38, task20);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma51_() {
  auto Gamma51 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma51 = Gamma51->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task21 = make_shared<Task21>(array<shared_ptr<Tensor>,3>{{Gamma51, make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma51, Gamma51, task21);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma56_() {
  auto Gamma56 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma56 = Gamma56->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task22 = make_shared<Task22>(array<shared_ptr<Tensor>,3>{{Gamma56, make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma56, Gamma56, task22);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma57_() {
  auto Gamma57 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma57 = Gamma57->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task23 = make_shared<Task23>(array<shared_ptr<Tensor>,3>{{Gamma57, make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma57, Gamma57, task23);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma58_() {
  auto Gamma58 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma58 = Gamma58->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task24 = make_shared<Task24>(array<shared_ptr<Tensor>,5>{{Gamma58, make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_), make_shared<Tensor>(*rdm4_), make_shared<Tensor>(*f1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma58, Gamma58, task24);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma59_() {
  auto Gamma59 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma59 = Gamma59->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task25 = make_shared<Task25>(array<shared_ptr<Tensor>,3>{{Gamma59, make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma59, Gamma59, task25);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma60_() {
  auto Gamma60 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma60 = Gamma60->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task26 = make_shared<Task26>(array<shared_ptr<Tensor>,2>{{Gamma60, make_shared<Tensor>(*rdm2_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma60, Gamma60, task26);
}

shared_ptr<FutureTATensor<std::complex<double>,2>> RelCASPT2::RelCASPT2::Gamma79_() {
  auto Gamma79 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_});
  auto TAGamma79 = Gamma79->tiledarray<2>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task27 = make_shared<Task27>(array<shared_ptr<Tensor>,3>{{Gamma79, make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*f1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,2>>(*TAGamma79, Gamma79, task27);
}

shared_ptr<FutureTATensor<std::complex<double>,4>> RelCASPT2::RelCASPT2::Gamma90_() {
  auto Gamma90 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_});
  auto TAGamma90 = Gamma90->tiledarray<4>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task28 = make_shared<Task28>(array<shared_ptr<Tensor>,3>{{Gamma90, make_shared<Tensor>(*rdm3_), make_shared<Tensor>(*f1_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,4>>(*TAGamma90, Gamma90, task28);
}

shared_ptr<FutureTATensor<std::complex<double>,6>> RelCASPT2::RelCASPT2::Gamma109_() {
  auto Gamma109 = make_shared<Tensor>(std::vector<IndexRange>{active_, active_, active_, active_, active_, active_});
  auto TAGamma109 = Gamma109->tiledarray<6>();
  array<shared_ptr<const IndexRange>,3> pindex = {{rclosed_, ractive_, rvirt_}};
  auto task29 = make_shared<Task29>(array<shared_ptr<Tensor>,4>{{Gamma109, make_shared<Tensor>(*rdm1_), make_shared<Tensor>(*rdm2_), make_shared<Tensor>(*rdm3_)}}, pindex);
  return make_shared<FutureTATensor<std::complex<double>,6>>(*TAGamma109, Gamma109, task29);
}

#endif
