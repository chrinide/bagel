//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: RelCASPT2_residualqq.cc
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

shared_ptr<Queue> RelCASPT2::RelCASPT2::make_residualq(const bool reset, const bool diagonal) {

  auto residualq = make_shared<Queue>();
  auto task30 = make_shared<Task30>(r, reset);
  residualq->add_task(task30);

  auto I0 = make_shared<TATensor<std::complex<double>,4>>({closed_, closed_, active_, active_});
  auto task31 = make_shared<Task31>(r, I0);
  task31->add_dep(task30);
  residualq->add_task(task31);

  auto task32 = make_shared<Task32>(I0, Gamma0_(), t2);
  task31->add_dep(task32);
  task32->add_dep(task30);
  residualq->add_task(task32);

  auto task33 = make_shared<Task33>(I0, Gamma92_(), t2, this->e0_);
  task31->add_dep(task33);
  task33->add_dep(task30);
  residualq->add_task(task33);

  auto I2 = make_shared<TATensor<std::complex<double>,4>>({closed_, closed_, active_, active_});
  auto task34 = make_shared<Task34>(r, I2);
  task34->add_dep(task30);
  residualq->add_task(task34);

  auto I3 = make_shared<TATensor<std::complex<double>,4>>({closed_, closed_, active_, active_});
  auto task35 = make_shared<Task35>(I2, Gamma92_(), I3);
  task34->add_dep(task35);
  task35->add_dep(task30);
  residualq->add_task(task35);

  auto task36 = make_shared<Task36>(I3, t2, f1_);
  task35->add_dep(task36);
  task36->add_dep(task30);
  residualq->add_task(task36);

  auto I6 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, active_, active_});
  auto task37 = make_shared<Task37>(I2, f1_, I6);
  task34->add_dep(task37);
  task37->add_dep(task30);
  residualq->add_task(task37);

  auto task38 = make_shared<Task38>(I6, Gamma2_(), t2);
  task37->add_dep(task38);
  task38->add_dep(task30);
  residualq->add_task(task38);

  auto I9 = make_shared<TATensor<std::complex<double>,4>>({active_, closed_, closed_, active_});
  auto task39 = make_shared<Task39>(I2, Gamma3_(), I9);
  task34->add_dep(task39);
  task39->add_dep(task30);
  residualq->add_task(task39);

  auto task40 = make_shared<Task40>(I9, t2, f1_);
  task39->add_dep(task40);
  task40->add_dep(task30);
  residualq->add_task(task40);

  auto I11 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, active_, active_});
  auto task41 = make_shared<Task41>(r, I11);
  task41->add_dep(task30);
  residualq->add_task(task41);

  auto I12 = make_shared<TATensor<std::complex<double>,4>>({active_, closed_, active_, active_});
  auto task42 = make_shared<Task42>(I11, Gamma4_(), I12);
  task41->add_dep(task42);
  task42->add_dep(task30);
  residualq->add_task(task42);

  auto task43 = make_shared<Task43>(I12, t2, f1_);
  task42->add_dep(task43);
  task43->add_dep(task30);
  residualq->add_task(task43);

  auto task44 = make_shared<Task44>(I11, Gamma5_(), t2);
  task41->add_dep(task44);
  task44->add_dep(task30);
  residualq->add_task(task44);

  auto I17 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, active_, active_});
  auto task45 = make_shared<Task45>(I11, Gamma6_(), I17);
  task41->add_dep(task45);
  task45->add_dep(task30);
  residualq->add_task(task45);

  auto task46 = make_shared<Task46>(I17, t2, this->e0_);
  task45->add_dep(task46);
  task46->add_dep(task30);
  residualq->add_task(task46);

  auto task47 = make_shared<Task47>(I17, t2, f1_);
  task45->add_dep(task47);
  task47->add_dep(task30);
  residualq->add_task(task47);

  auto task48 = make_shared<Task48>(I17, t2, f1_);
  task45->add_dep(task48);
  task48->add_dep(task30);
  residualq->add_task(task48);

  auto I20 = make_shared<TATensor<std::complex<double>,2>>({closed_, active_});
  auto task49 = make_shared<Task49>(I11, Gamma7_(), I20);
  task41->add_dep(task49);
  task49->add_dep(task30);
  residualq->add_task(task49);

  auto task50 = make_shared<Task50>(I20, t2, f1_);
  task49->add_dep(task50);
  task50->add_dep(task30);
  residualq->add_task(task50);

  auto task51 = make_shared<Task51>(I20, t2, f1_);
  task49->add_dep(task51);
  task51->add_dep(task30);
  residualq->add_task(task51);

  auto I26 = make_shared<TATensor<std::complex<double>,4>>({active_, active_, closed_, active_});
  auto task52 = make_shared<Task52>(I11, Gamma9_(), I26);
  task41->add_dep(task52);
  task52->add_dep(task30);
  residualq->add_task(task52);

  auto task53 = make_shared<Task53>(I26, t2, f1_);
  task52->add_dep(task53);
  task53->add_dep(task30);
  residualq->add_task(task53);

  auto I31 = make_shared<TATensor<std::complex<double>,4>>({closed_, closed_, active_, virt_});
  auto task54 = make_shared<Task54>(r, I31);
  task54->add_dep(task30);
  residualq->add_task(task54);

  auto I32 = make_shared<TATensor<std::complex<double>,4>>({closed_, closed_, active_, active_});
  auto task55 = make_shared<Task55>(I31, f1_, I32);
  task54->add_dep(task55);
  task55->add_dep(task30);
  residualq->add_task(task55);

  auto task56 = make_shared<Task56>(I32, Gamma3_(), t2);
  task55->add_dep(task56);
  task56->add_dep(task30);
  residualq->add_task(task56);

  auto I35 = make_shared<TATensor<std::complex<double>,2>>({closed_, active_});
  auto task57 = make_shared<Task57>(I31, f1_, I35);
  task54->add_dep(task57);
  task57->add_dep(task30);
  residualq->add_task(task57);

  auto task58 = make_shared<Task58>(I35, Gamma12_(), t2);
  task57->add_dep(task58);
  task58->add_dep(task30);
  residualq->add_task(task58);

  auto I38 = make_shared<TATensor<std::complex<double>,2>>({closed_, active_});
  auto task59 = make_shared<Task59>(I31, f1_, I38);
  task54->add_dep(task59);
  task59->add_dep(task30);
  residualq->add_task(task59);

  auto task60 = make_shared<Task60>(I38, Gamma12_(), t2);
  task59->add_dep(task60);
  task60->add_dep(task30);
  residualq->add_task(task60);

  auto I41 = make_shared<TATensor<std::complex<double>,4>>({closed_, virt_, closed_, active_});
  auto task61 = make_shared<Task61>(I31, Gamma14_(), I41);
  task54->add_dep(task61);
  task61->add_dep(task30);
  residualq->add_task(task61);

  auto task62 = make_shared<Task62>(I41, t2);
  task61->add_dep(task62);
  task62->add_dep(task30);
  residualq->add_task(task62);

  auto I45 = make_shared<TATensor<std::complex<double>,4>>({closed_, virt_, closed_, active_});
  auto task63 = make_shared<Task63>(I31, Gamma16_(), I45);
  task54->add_dep(task63);
  task63->add_dep(task30);
  residualq->add_task(task63);

  auto task64 = make_shared<Task64>(I45, t2, this->e0_);
  task63->add_dep(task64);
  task64->add_dep(task30);
  residualq->add_task(task64);

  auto task65 = make_shared<Task65>(I45, t2, f1_);
  task63->add_dep(task65);
  task65->add_dep(task30);
  residualq->add_task(task65);

  auto task66 = make_shared<Task66>(I45, t2, f1_);
  task63->add_dep(task66);
  task66->add_dep(task30);
  residualq->add_task(task66);

  auto task67 = make_shared<Task67>(I45, t2, f1_);
  task63->add_dep(task67);
  task67->add_dep(task30);
  residualq->add_task(task67);

  auto task68 = make_shared<Task68>(I45, t2, f1_);
  task63->add_dep(task68);
  task68->add_dep(task30);
  residualq->add_task(task68);

  auto task69 = make_shared<Task69>(I45, t2, f1_);
  task63->add_dep(task69);
  task69->add_dep(task30);
  residualq->add_task(task69);

  auto task70 = make_shared<Task70>(I45, t2, f1_);
  task63->add_dep(task70);
  task70->add_dep(task30);
  residualq->add_task(task70);

  auto I63 = make_shared<TATensor<std::complex<double>,4>>({virt_, closed_, active_, active_});
  auto task71 = make_shared<Task71>(I31, f1_, I63);
  task54->add_dep(task71);
  task71->add_dep(task30);
  residualq->add_task(task71);

  auto task72 = make_shared<Task72>(I63, Gamma22_(), t2);
  task71->add_dep(task72);
  task72->add_dep(task30);
  residualq->add_task(task72);

  auto task73 = make_shared<Task73>(I63, Gamma12_(), t2);
  task71->add_dep(task73);
  task73->add_dep(task30);
  residualq->add_task(task73);

  auto I66 = make_shared<TATensor<std::complex<double>,4>>({virt_, closed_, active_, active_});
  auto task74 = make_shared<Task74>(I31, f1_, I66);
  task54->add_dep(task74);
  task74->add_dep(task30);
  residualq->add_task(task74);

  auto I67 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, closed_, active_});
  auto task75 = make_shared<Task75>(I66, Gamma12_(), I67);
  task74->add_dep(task75);
  task75->add_dep(task30);
  residualq->add_task(task75);

  auto task76 = make_shared<Task76>(I67, t2);
  task75->add_dep(task76);
  task76->add_dep(task30);
  residualq->add_task(task76);

  auto I75 = make_shared<TATensor<std::complex<double>,2>>({virt_, active_});
  auto task77 = make_shared<Task77>(I31, t2, I75);
  task54->add_dep(task77);
  task77->add_dep(task30);
  residualq->add_task(task77);

  auto task78 = make_shared<Task78>(I75, Gamma16_(), f1_);
  task77->add_dep(task78);
  task78->add_dep(task30);
  residualq->add_task(task78);

  auto I78 = make_shared<TATensor<std::complex<double>,2>>({virt_, active_});
  auto task79 = make_shared<Task79>(I31, t2, I78);
  task54->add_dep(task79);
  task79->add_dep(task30);
  residualq->add_task(task79);

  auto task80 = make_shared<Task80>(I78, Gamma16_(), f1_);
  task79->add_dep(task80);
  task80->add_dep(task30);
  residualq->add_task(task80);

  auto I80 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, active_, virt_});
  auto task81 = make_shared<Task81>(r, I80);
  task81->add_dep(task30);
  residualq->add_task(task81);

  auto I81 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, active_, active_});
  auto task82 = make_shared<Task82>(I80, f1_, I81);
  task81->add_dep(task82);
  task82->add_dep(task30);
  residualq->add_task(task82);

  auto task83 = make_shared<Task83>(I81, Gamma28_(), t2);
  task82->add_dep(task83);
  task83->add_dep(task30);
  residualq->add_task(task83);

  auto I84 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, closed_, active_});
  auto task84 = make_shared<Task84>(I80, Gamma29_(), I84);
  task81->add_dep(task84);
  task84->add_dep(task30);
  residualq->add_task(task84);

  auto task85 = make_shared<Task85>(I84, t2, f1_);
  task84->add_dep(task85);
  task85->add_dep(task30);
  residualq->add_task(task85);

  auto I87 = make_shared<TATensor<std::complex<double>,4>>({active_, closed_, virt_, active_});
  auto task86 = make_shared<Task86>(I80, Gamma7_(), I87);
  task81->add_dep(task86);
  task86->add_dep(task30);
  residualq->add_task(task86);

  auto task87 = make_shared<Task87>(I87, t2, f1_);
  task86->add_dep(task87);
  task87->add_dep(task30);
  residualq->add_task(task87);

  auto task88 = make_shared<Task88>(I80, Gamma31_(), t2);
  task81->add_dep(task88);
  task88->add_dep(task30);
  residualq->add_task(task88);

  auto I92 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, virt_, active_});
  auto task89 = make_shared<Task89>(I80, Gamma32_(), I92);
  task81->add_dep(task89);
  task89->add_dep(task30);
  residualq->add_task(task89);

  auto task90 = make_shared<Task90>(I92, t2, this->e0_);
  task89->add_dep(task90);
  task90->add_dep(task30);
  residualq->add_task(task90);

  auto task91 = make_shared<Task91>(I92, t2, f1_);
  task89->add_dep(task91);
  task91->add_dep(task30);
  residualq->add_task(task91);

  auto task92 = make_shared<Task92>(I92, t2, f1_);
  task89->add_dep(task92);
  task92->add_dep(task30);
  residualq->add_task(task92);

  auto task93 = make_shared<Task93>(I92, t2, f1_);
  task89->add_dep(task93);
  task93->add_dep(task30);
  residualq->add_task(task93);

  auto task94 = make_shared<Task94>(I80, Gamma34_(), t2);
  task81->add_dep(task94);
  task94->add_dep(task30);
  residualq->add_task(task94);

  auto I100 = make_shared<TATensor<std::complex<double>,4>>({closed_, virt_, active_, active_});
  auto task95 = make_shared<Task95>(I80, Gamma35_(), I100);
  task81->add_dep(task95);
  task95->add_dep(task30);
  residualq->add_task(task95);

  auto task96 = make_shared<Task96>(I100, t2, this->e0_);
  task95->add_dep(task96);
  task96->add_dep(task30);
  residualq->add_task(task96);

  auto task97 = make_shared<Task97>(I100, t2, f1_);
  task95->add_dep(task97);
  task97->add_dep(task30);
  residualq->add_task(task97);

  auto task98 = make_shared<Task98>(I100, t2, f1_);
  task95->add_dep(task98);
  task98->add_dep(task30);
  residualq->add_task(task98);

  auto task99 = make_shared<Task99>(I100, t2, f1_);
  task95->add_dep(task99);
  task99->add_dep(task30);
  residualq->add_task(task99);

  auto I106 = make_shared<TATensor<std::complex<double>,4>>({virt_, active_, active_, active_});
  auto task100 = make_shared<Task100>(I80, f1_, I106);
  task81->add_dep(task100);
  task100->add_dep(task30);
  residualq->add_task(task100);

  auto task101 = make_shared<Task101>(I106, Gamma37_(), t2);
  task100->add_dep(task101);
  task101->add_dep(task30);
  residualq->add_task(task101);

  auto I109 = make_shared<TATensor<std::complex<double>,2>>({closed_, virt_});
  auto task102 = make_shared<Task102>(I80, Gamma38_(), I109);
  task81->add_dep(task102);
  task102->add_dep(task30);
  residualq->add_task(task102);

  auto task103 = make_shared<Task103>(I109, t2, f1_);
  task102->add_dep(task103);
  task103->add_dep(task30);
  residualq->add_task(task103);

  auto task104 = make_shared<Task104>(I109, t2, f1_);
  task102->add_dep(task104);
  task104->add_dep(task30);
  residualq->add_task(task104);

  auto I120 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, active_, virt_});
  auto task105 = make_shared<Task105>(r, I120);
  task105->add_dep(task30);
  residualq->add_task(task105);

  auto I121 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, active_, active_});
  auto task106 = make_shared<Task106>(I120, f1_, I121);
  task105->add_dep(task106);
  task106->add_dep(task30);
  residualq->add_task(task106);

  auto task107 = make_shared<Task107>(I121, Gamma6_(), t2);
  task106->add_dep(task107);
  task107->add_dep(task30);
  residualq->add_task(task107);

  auto I124 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, closed_, active_});
  auto task108 = make_shared<Task108>(I120, Gamma7_(), I124);
  task105->add_dep(task108);
  task108->add_dep(task30);
  residualq->add_task(task108);

  auto task109 = make_shared<Task109>(I124, t2, f1_);
  task108->add_dep(task109);
  task109->add_dep(task30);
  residualq->add_task(task109);

  auto task110 = make_shared<Task110>(I124, t2, f1_);
  task108->add_dep(task110);
  task110->add_dep(task30);
  residualq->add_task(task110);

  auto I130 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, closed_, active_});
  auto task111 = make_shared<Task111>(I120, Gamma34_(), I130);
  task105->add_dep(task111);
  task111->add_dep(task30);
  residualq->add_task(task111);

  auto task112 = make_shared<Task112>(I130, t2);
  task111->add_dep(task112);
  task112->add_dep(task30);
  residualq->add_task(task112);

  auto I132 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, virt_, active_});
  auto task113 = make_shared<Task113>(I120, Gamma35_(), I132);
  task105->add_dep(task113);
  task113->add_dep(task30);
  residualq->add_task(task113);

  auto task114 = make_shared<Task114>(I132, t2, this->e0_);
  task113->add_dep(task114);
  task114->add_dep(task30);
  residualq->add_task(task114);

  auto task115 = make_shared<Task115>(I132, t2, f1_);
  task113->add_dep(task115);
  task115->add_dep(task30);
  residualq->add_task(task115);

  auto task116 = make_shared<Task116>(I132, t2, f1_);
  task113->add_dep(task116);
  task116->add_dep(task30);
  residualq->add_task(task116);

  auto task117 = make_shared<Task117>(I132, t2, f1_);
  task113->add_dep(task117);
  task117->add_dep(task30);
  residualq->add_task(task117);

  auto task118 = make_shared<Task118>(I132, t2, f1_);
  task113->add_dep(task118);
  task118->add_dep(task30);
  residualq->add_task(task118);

  auto task119 = make_shared<Task119>(I132, t2, f1_);
  task113->add_dep(task119);
  task119->add_dep(task30);
  residualq->add_task(task119);

  auto task120 = make_shared<Task120>(I132, t2, f1_);
  task113->add_dep(task120);
  task120->add_dep(task30);
  residualq->add_task(task120);

  auto I146 = make_shared<TATensor<std::complex<double>,4>>({virt_, active_, active_, active_});
  auto task121 = make_shared<Task121>(I120, f1_, I146);
  task105->add_dep(task121);
  task121->add_dep(task30);
  residualq->add_task(task121);

  auto task122 = make_shared<Task122>(I146, Gamma51_(), t2);
  task121->add_dep(task122);
  task122->add_dep(task30);
  residualq->add_task(task122);

  auto I149 = make_shared<TATensor<std::complex<double>,2>>({closed_, virt_});
  auto task123 = make_shared<Task123>(I120, Gamma38_(), I149);
  task105->add_dep(task123);
  task123->add_dep(task30);
  residualq->add_task(task123);

  auto task124 = make_shared<Task124>(I149, t2, f1_);
  task123->add_dep(task124);
  task124->add_dep(task30);
  residualq->add_task(task124);

  auto task125 = make_shared<Task125>(I149, t2, f1_);
  task123->add_dep(task125);
  task125->add_dep(task30);
  residualq->add_task(task125);

  auto I160 = make_shared<TATensor<std::complex<double>,4>>({virt_, active_, active_, active_});
  auto task126 = make_shared<Task126>(r, I160);
  task126->add_dep(task30);
  residualq->add_task(task126);

  auto I161 = make_shared<TATensor<std::complex<double>,4>>({active_, active_, virt_, active_});
  auto task127 = make_shared<Task127>(I160, Gamma56_(), I161);
  task126->add_dep(task127);
  task127->add_dep(task30);
  residualq->add_task(task127);

  auto task128 = make_shared<Task128>(I161, t2, f1_);
  task127->add_dep(task128);
  task128->add_dep(task30);
  residualq->add_task(task128);

  auto I164 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, active_, active_});
  auto task129 = make_shared<Task129>(I160, Gamma57_(), I164);
  task126->add_dep(task129);
  task129->add_dep(task30);
  residualq->add_task(task129);

  auto task130 = make_shared<Task130>(I164, t2, f1_);
  task129->add_dep(task130);
  task130->add_dep(task30);
  residualq->add_task(task130);

  auto task131 = make_shared<Task131>(I160, Gamma58_(), t2);
  task126->add_dep(task131);
  task131->add_dep(task30);
  residualq->add_task(task131);

  auto I169 = make_shared<TATensor<std::complex<double>,4>>({virt_, active_, active_, active_});
  auto task132 = make_shared<Task132>(I160, Gamma59_(), I169);
  task126->add_dep(task132);
  task132->add_dep(task30);
  residualq->add_task(task132);

  auto task133 = make_shared<Task133>(I169, t2, this->e0_);
  task132->add_dep(task133);
  task133->add_dep(task30);
  residualq->add_task(task133);

  auto task134 = make_shared<Task134>(I169, t2, f1_);
  task132->add_dep(task134);
  task134->add_dep(task30);
  residualq->add_task(task134);

  auto task135 = make_shared<Task135>(I169, t2, f1_);
  task132->add_dep(task135);
  task135->add_dep(task30);
  residualq->add_task(task135);

  auto I172 = make_shared<TATensor<std::complex<double>,2>>({active_, virt_});
  auto task136 = make_shared<Task136>(I160, Gamma60_(), I172);
  task126->add_dep(task136);
  task136->add_dep(task30);
  residualq->add_task(task136);

  auto task137 = make_shared<Task137>(I172, t2, f1_);
  task136->add_dep(task137);
  task137->add_dep(task30);
  residualq->add_task(task137);

  auto task138 = make_shared<Task138>(I172, t2, f1_);
  task136->add_dep(task138);
  task138->add_dep(task30);
  residualq->add_task(task138);

  auto I180 = make_shared<TATensor<std::complex<double>,4>>({virt_, closed_, virt_, closed_});
  auto task139 = make_shared<Task139>(r, I180);
  task139->add_dep(task30);
  residualq->add_task(task139);

  auto I181 = make_shared<TATensor<std::complex<double>,2>>({virt_, active_});
  auto task140 = make_shared<Task140>(I180, t2, I181);
  task139->add_dep(task140);
  task140->add_dep(task30);
  residualq->add_task(task140);

  auto task141 = make_shared<Task141>(I181, Gamma16_(), f1_);
  task140->add_dep(task141);
  task141->add_dep(task30);
  residualq->add_task(task141);

  auto I184 = make_shared<TATensor<std::complex<double>,2>>({virt_, active_});
  auto task142 = make_shared<Task142>(I180, t2, I184);
  task139->add_dep(task142);
  task142->add_dep(task30);
  residualq->add_task(task142);

  auto task143 = make_shared<Task143>(I184, Gamma16_(), f1_);
  task142->add_dep(task143);
  task143->add_dep(task30);
  residualq->add_task(task143);

  auto I187 = make_shared<TATensor<std::complex<double>,2>>({virt_, closed_});
  auto task144 = make_shared<Task144>(I180, f1_, I187);
  task139->add_dep(task144);
  task144->add_dep(task30);
  residualq->add_task(task144);

  auto I188 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, closed_, active_});
  auto task145 = make_shared<Task145>(I187, Gamma38_(), I188);
  task144->add_dep(task145);
  task145->add_dep(task30);
  residualq->add_task(task145);

  auto task146 = make_shared<Task146>(I188, t2);
  task145->add_dep(task146);
  task146->add_dep(task30);
  residualq->add_task(task146);

  auto I190 = make_shared<TATensor<std::complex<double>,2>>({virt_, closed_});
  auto task147 = make_shared<Task147>(I180, f1_, I190);
  task139->add_dep(task147);
  task147->add_dep(task30);
  residualq->add_task(task147);

  auto I191 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, closed_, active_});
  auto task148 = make_shared<Task148>(I190, Gamma38_(), I191);
  task147->add_dep(task148);
  task148->add_dep(task30);
  residualq->add_task(task148);

  auto task149 = make_shared<Task149>(I191, t2);
  task148->add_dep(task149);
  task149->add_dep(task30);
  residualq->add_task(task149);

  auto I199 = make_shared<TATensor<std::complex<double>,2>>({closed_, active_});
  auto task150 = make_shared<Task150>(I180, t2, I199);
  task139->add_dep(task150);
  task150->add_dep(task30);
  residualq->add_task(task150);

  auto task151 = make_shared<Task151>(I199, Gamma38_(), f1_);
  task150->add_dep(task151);
  task151->add_dep(task30);
  residualq->add_task(task151);

  auto I202 = make_shared<TATensor<std::complex<double>,2>>({closed_, active_});
  auto task152 = make_shared<Task152>(I180, t2, I202);
  task139->add_dep(task152);
  task152->add_dep(task30);
  residualq->add_task(task152);

  auto task153 = make_shared<Task153>(I202, Gamma38_(), f1_);
  task152->add_dep(task153);
  task153->add_dep(task30);
  residualq->add_task(task153);

  auto I204 = make_shared<TATensor<std::complex<double>,4>>({virt_, closed_, active_, virt_});
  auto task154 = make_shared<Task154>(r, I204);
  task154->add_dep(task30);
  residualq->add_task(task154);

  auto I205 = make_shared<TATensor<std::complex<double>,4>>({virt_, closed_, active_, active_});
  auto task155 = make_shared<Task155>(I204, f1_, I205);
  task154->add_dep(task155);
  task155->add_dep(task30);
  residualq->add_task(task155);

  auto I206 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, closed_, active_});
  auto task156 = make_shared<Task156>(I205, Gamma35_(), I206);
  task155->add_dep(task156);
  task156->add_dep(task30);
  residualq->add_task(task156);

  auto task157 = make_shared<Task157>(I206, t2);
  task156->add_dep(task157);
  task157->add_dep(task30);
  residualq->add_task(task157);

  auto I208 = make_shared<TATensor<std::complex<double>,4>>({virt_, closed_, active_, active_});
  auto task158 = make_shared<Task158>(I204, f1_, I208);
  task154->add_dep(task158);
  task158->add_dep(task30);
  residualq->add_task(task158);

  auto task159 = make_shared<Task159>(I208, Gamma32_(), t2);
  task158->add_dep(task159);
  task159->add_dep(task30);
  residualq->add_task(task159);

  auto task160 = make_shared<Task160>(I208, Gamma35_(), t2);
  task158->add_dep(task160);
  task160->add_dep(task30);
  residualq->add_task(task160);

  auto I217 = make_shared<TATensor<std::complex<double>,2>>({virt_, active_});
  auto task161 = make_shared<Task161>(I204, f1_, I217);
  task154->add_dep(task161);
  task161->add_dep(task30);
  residualq->add_task(task161);

  auto task162 = make_shared<Task162>(I217, Gamma60_(), t2);
  task161->add_dep(task162);
  task162->add_dep(task30);
  residualq->add_task(task162);

  auto I220 = make_shared<TATensor<std::complex<double>,2>>({virt_, active_});
  auto task163 = make_shared<Task163>(I204, f1_, I220);
  task154->add_dep(task163);
  task163->add_dep(task30);
  residualq->add_task(task163);

  auto task164 = make_shared<Task164>(I220, Gamma60_(), t2);
  task163->add_dep(task164);
  task164->add_dep(task30);
  residualq->add_task(task164);

  auto I223 = make_shared<TATensor<std::complex<double>,2>>({closed_, active_});
  auto task165 = make_shared<Task165>(I204, t2, I223);
  task154->add_dep(task165);
  task165->add_dep(task30);
  residualq->add_task(task165);

  auto task166 = make_shared<Task166>(I223, Gamma38_(), f1_);
  task165->add_dep(task166);
  task166->add_dep(task30);
  residualq->add_task(task166);

  auto I226 = make_shared<TATensor<std::complex<double>,2>>({closed_, active_});
  auto task167 = make_shared<Task167>(I204, t2, I226);
  task154->add_dep(task167);
  task167->add_dep(task30);
  residualq->add_task(task167);

  auto task168 = make_shared<Task168>(I226, Gamma38_(), f1_);
  task167->add_dep(task168);
  task168->add_dep(task30);
  residualq->add_task(task168);

  auto I229 = make_shared<TATensor<std::complex<double>,4>>({active_, virt_, closed_, virt_});
  auto task169 = make_shared<Task169>(I204, Gamma79_(), I229);
  task154->add_dep(task169);
  task169->add_dep(task30);
  residualq->add_task(task169);

  auto task170 = make_shared<Task170>(I229, t2);
  task169->add_dep(task170);
  task170->add_dep(task30);
  residualq->add_task(task170);

  auto I233 = make_shared<TATensor<std::complex<double>,4>>({closed_, active_, virt_, virt_});
  auto task171 = make_shared<Task171>(I204, Gamma38_(), I233);
  task154->add_dep(task171);
  task171->add_dep(task30);
  residualq->add_task(task171);

  auto task172 = make_shared<Task172>(I233, t2, this->e0_);
  task171->add_dep(task172);
  task172->add_dep(task30);
  residualq->add_task(task172);

  auto task173 = make_shared<Task173>(I233, t2, f1_);
  task171->add_dep(task173);
  task173->add_dep(task30);
  residualq->add_task(task173);

  auto task174 = make_shared<Task174>(I233, t2, f1_);
  task171->add_dep(task174);
  task174->add_dep(task30);
  residualq->add_task(task174);

  auto task175 = make_shared<Task175>(I233, t2, f1_);
  task171->add_dep(task175);
  task175->add_dep(task30);
  residualq->add_task(task175);

  auto task176 = make_shared<Task176>(I233, t2, f1_);
  task171->add_dep(task176);
  task176->add_dep(task30);
  residualq->add_task(task176);

  auto task177 = make_shared<Task177>(I233, t2, f1_);
  task171->add_dep(task177);
  task177->add_dep(task30);
  residualq->add_task(task177);

  auto task178 = make_shared<Task178>(I233, t2, f1_);
  task171->add_dep(task178);
  task178->add_dep(task30);
  residualq->add_task(task178);

  auto I251 = make_shared<TATensor<std::complex<double>,4>>({virt_, virt_, active_, active_});
  auto task179 = make_shared<Task179>(I204, f1_, I251);
  task154->add_dep(task179);
  task179->add_dep(task30);
  residualq->add_task(task179);

  auto task180 = make_shared<Task180>(I251, Gamma60_(), t2);
  task179->add_dep(task180);
  task180->add_dep(task30);
  residualq->add_task(task180);

  auto I253 = make_shared<TATensor<std::complex<double>,4>>({virt_, active_, active_, virt_});
  auto task181 = make_shared<Task181>(r, I253);
  task181->add_dep(task30);
  residualq->add_task(task181);

  auto I254 = make_shared<TATensor<std::complex<double>,4>>({virt_, active_, active_, active_});
  auto task182 = make_shared<Task182>(I253, f1_, I254);
  task181->add_dep(task182);
  task182->add_dep(task30);
  residualq->add_task(task182);

  auto task183 = make_shared<Task183>(I254, Gamma59_(), t2);
  task182->add_dep(task183);
  task183->add_dep(task30);
  residualq->add_task(task183);

  auto I257 = make_shared<TATensor<std::complex<double>,4>>({active_, active_, virt_, virt_});
  auto task184 = make_shared<Task184>(I253, Gamma60_(), I257);
  task181->add_dep(task184);
  task184->add_dep(task30);
  residualq->add_task(task184);

  auto task185 = make_shared<Task185>(I257, t2, f1_);
  task184->add_dep(task185);
  task185->add_dep(task30);
  residualq->add_task(task185);

  auto task186 = make_shared<Task186>(I257, t2, f1_);
  task184->add_dep(task186);
  task186->add_dep(task30);
  residualq->add_task(task186);

  auto I259 = make_shared<TATensor<std::complex<double>,4>>({virt_, virt_, active_, active_});
  auto task187 = make_shared<Task187>(r, I259);
  task187->add_dep(task30);
  residualq->add_task(task187);

  auto task188 = make_shared<Task188>(I259, Gamma90_(), t2);
  task187->add_dep(task188);
  task188->add_dep(task30);
  residualq->add_task(task188);

  auto task189 = make_shared<Task189>(I259, Gamma60_(), t2, this->e0_);
  task187->add_dep(task189);
  task189->add_dep(task30);
  residualq->add_task(task189);

  return residualq;
}


#endif
