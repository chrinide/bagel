//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: RelCASPT2_tasks4.h
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

#ifndef __SRC_SMITH_RelCASPT2_TASKS4_H
#define __SRC_SMITH_RelCASPT2_TASKS4_H

#include <src/smith/indexrange.h>
#include <src/smith/tensor.h>
#include <src/smith/task.h>
#include <src/smith/subtask.h>
#include <src/smith/storage.h>

namespace bagel {
namespace SMITH {
namespace RelCASPT2{

class Task150 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task150(std::shared_ptr<TATensor<std::complex<double>,4>> I180, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> I199)
   : ta0_(I180), ta1_(t2), ta2_(I199) { }
};

class Task151 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,2>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task151(std::shared_ptr<TATensor<std::complex<double>,2>> I199, std::shared_ptr<TATensor<std::complex<double>,2>> Gamma38, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I199), ta1_(Gamma38), ta2_(f1) { }
};

class Task152 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task152(std::shared_ptr<TATensor<std::complex<double>,4>> I180, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> I202)
   : ta0_(I180), ta1_(t2), ta2_(I202) { }
};

class Task153 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,2>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task153(std::shared_ptr<TATensor<std::complex<double>,2>> I202, std::shared_ptr<TATensor<std::complex<double>,2>> Gamma38, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I202), ta1_(Gamma38), ta2_(f1) { }
};

class Task154 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    void compute_() override;
  public:
    Task154(std::shared_ptr<TATensor<std::complex<double>,4>> proj, std::shared_ptr<TATensor<std::complex<double>,4>> I204)
   : ta0_(proj), ta1_(I204) { }
};

class Task155 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task155(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,2>> f1, std::shared_ptr<TATensor<std::complex<double>,4>> I205)
   : ta0_(I204), ta1_(f1), ta2_(I205) { }
};

class Task156 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task156(std::shared_ptr<TATensor<std::complex<double>,4>> I205, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma35, std::shared_ptr<TATensor<std::complex<double>,4>> I206)
   : ta0_(I205), ta1_(Gamma35), ta2_(I206) { }
};

class Task157 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    void compute_() override;
  public:
    Task157(std::shared_ptr<TATensor<std::complex<double>,4>> I206, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I206), ta1_(t2) { }
};

class Task158 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task158(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,2>> f1, std::shared_ptr<TATensor<std::complex<double>,4>> I208)
   : ta0_(I204), ta1_(f1), ta2_(I208) { }
};

class Task159 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task159(std::shared_ptr<TATensor<std::complex<double>,4>> I208, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma32, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I208), ta1_(Gamma32), ta2_(t2) { }
};

class Task160 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task160(std::shared_ptr<TATensor<std::complex<double>,4>> I208, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma35, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I208), ta1_(Gamma35), ta2_(t2) { }
};

class Task161 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task161(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,2>> f1, std::shared_ptr<TATensor<std::complex<double>,2>> I217)
   : ta0_(I204), ta1_(f1), ta2_(I217) { }
};

class Task162 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,2>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task162(std::shared_ptr<TATensor<std::complex<double>,2>> I217, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma60, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I217), ta1_(Gamma60), ta2_(t2) { }
};

class Task163 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task163(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,2>> f1, std::shared_ptr<TATensor<std::complex<double>,2>> I220)
   : ta0_(I204), ta1_(f1), ta2_(I220) { }
};

class Task164 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,2>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task164(std::shared_ptr<TATensor<std::complex<double>,2>> I220, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma60, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I220), ta1_(Gamma60), ta2_(t2) { }
};

class Task165 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task165(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> I223)
   : ta0_(I204), ta1_(t2), ta2_(I223) { }
};

class Task166 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,2>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task166(std::shared_ptr<TATensor<std::complex<double>,2>> I223, std::shared_ptr<TATensor<std::complex<double>,2>> Gamma38, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I223), ta1_(Gamma38), ta2_(f1) { }
};

class Task167 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task167(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> I226)
   : ta0_(I204), ta1_(t2), ta2_(I226) { }
};

class Task168 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,2>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task168(std::shared_ptr<TATensor<std::complex<double>,2>> I226, std::shared_ptr<TATensor<std::complex<double>,2>> Gamma38, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I226), ta1_(Gamma38), ta2_(f1) { }
};

class Task169 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task169(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,2>> Gamma79, std::shared_ptr<TATensor<std::complex<double>,4>> I229)
   : ta0_(I204), ta1_(Gamma79), ta2_(I229) { }
};

class Task170 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    void compute_() override;
  public:
    Task170(std::shared_ptr<TATensor<std::complex<double>,4>> I229, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I229), ta1_(t2) { }
};

class Task171 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task171(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,2>> Gamma38, std::shared_ptr<TATensor<std::complex<double>,4>> I233)
   : ta0_(I204), ta1_(Gamma38), ta2_(I233) { }
};

class Task172 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    const double e0_;
    void compute_() override;
  public:
    Task172(std::shared_ptr<TATensor<std::complex<double>,4>> I233, std::shared_ptr<TATensor<std::complex<double>,4>> t2, const double e)
   : ta0_(I233), ta1_(t2), e0_(e) { }
};

class Task173 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task173(std::shared_ptr<TATensor<std::complex<double>,4>> I233, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I233), ta1_(t2), ta2_(f1) { }
};

class Task174 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task174(std::shared_ptr<TATensor<std::complex<double>,4>> I233, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I233), ta1_(t2), ta2_(f1) { }
};

class Task175 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task175(std::shared_ptr<TATensor<std::complex<double>,4>> I233, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I233), ta1_(t2), ta2_(f1) { }
};

class Task176 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task176(std::shared_ptr<TATensor<std::complex<double>,4>> I233, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I233), ta1_(t2), ta2_(f1) { }
};

class Task177 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task177(std::shared_ptr<TATensor<std::complex<double>,4>> I233, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I233), ta1_(t2), ta2_(f1) { }
};

class Task178 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task178(std::shared_ptr<TATensor<std::complex<double>,4>> I233, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I233), ta1_(t2), ta2_(f1) { }
};

class Task179 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task179(std::shared_ptr<TATensor<std::complex<double>,4>> I204, std::shared_ptr<TATensor<std::complex<double>,2>> f1, std::shared_ptr<TATensor<std::complex<double>,4>> I251)
   : ta0_(I204), ta1_(f1), ta2_(I251) { }
};

class Task180 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task180(std::shared_ptr<TATensor<std::complex<double>,4>> I251, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma60, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I251), ta1_(Gamma60), ta2_(t2) { }
};

class Task181 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    void compute_() override;
  public:
    Task181(std::shared_ptr<TATensor<std::complex<double>,4>> proj, std::shared_ptr<TATensor<std::complex<double>,4>> I253)
   : ta0_(proj), ta1_(I253) { }
};

class Task182 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task182(std::shared_ptr<TATensor<std::complex<double>,4>> I253, std::shared_ptr<TATensor<std::complex<double>,2>> f1, std::shared_ptr<TATensor<std::complex<double>,4>> I254)
   : ta0_(I253), ta1_(f1), ta2_(I254) { }
};

class Task183 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,6>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task183(std::shared_ptr<TATensor<std::complex<double>,4>> I254, std::shared_ptr<TATensor<std::complex<double>,6>> Gamma59, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I254), ta1_(Gamma59), ta2_(t2) { }
};

class Task184 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task184(std::shared_ptr<TATensor<std::complex<double>,4>> I253, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma60, std::shared_ptr<TATensor<std::complex<double>,4>> I257)
   : ta0_(I253), ta1_(Gamma60), ta2_(I257) { }
};

class Task185 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task185(std::shared_ptr<TATensor<std::complex<double>,4>> I257, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I257), ta1_(t2), ta2_(f1) { }
};

class Task186 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task186(std::shared_ptr<TATensor<std::complex<double>,4>> I257, std::shared_ptr<TATensor<std::complex<double>,4>> t2, std::shared_ptr<TATensor<std::complex<double>,2>> f1)
   : ta0_(I257), ta1_(t2), ta2_(f1) { }
};

class Task187 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    void compute_() override;
  public:
    Task187(std::shared_ptr<TATensor<std::complex<double>,4>> proj, std::shared_ptr<TATensor<std::complex<double>,4>> I259)
   : ta0_(proj), ta1_(I259) { }
};

class Task188 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task188(std::shared_ptr<TATensor<std::complex<double>,4>> I259, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma90, std::shared_ptr<TATensor<std::complex<double>,4>> t2)
   : ta0_(I259), ta1_(Gamma90), ta2_(t2) { }
};

class Task189 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    const double e0_;
    void compute_() override;
  public:
    Task189(std::shared_ptr<TATensor<std::complex<double>,4>> I259, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma60, std::shared_ptr<TATensor<std::complex<double>,4>> t2, const double e)
   : ta0_(I259), ta1_(Gamma60), ta2_(t2), e0_(e) { }
};

class Task190 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> tensor_;
    const bool reset_;
    void compute_() {
      if (reset_) tensor_->zero();
    }
  public:
    Task190(std::shared_ptr<TATensor<std::complex<double>,4>> t, const bool reset) : tensor_(t), reset_(reset) { }
};

class Task191 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    void compute_() override;
  public:
    Task191(std::shared_ptr<TATensor<std::complex<double>,4>> proj, std::shared_ptr<TATensor<std::complex<double>,4>> I288)
   : ta0_(proj), ta1_(I288) { }
};

class Task192 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task192(std::shared_ptr<TATensor<std::complex<double>,4>> I288, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma7, std::shared_ptr<TATensor<std::complex<double>,2>> h1)
   : ta0_(I288), ta1_(Gamma7), ta2_(h1) { }
};

class Task193 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,6>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task193(std::shared_ptr<TATensor<std::complex<double>,4>> I288, std::shared_ptr<TATensor<std::complex<double>,6>> Gamma109, std::shared_ptr<TATensor<std::complex<double>,4>> v2)
   : ta0_(I288), ta1_(Gamma109), ta2_(v2) { }
};

class Task194 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,6>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task194(std::shared_ptr<TATensor<std::complex<double>,4>> I288, std::shared_ptr<TATensor<std::complex<double>,6>> Gamma6, std::shared_ptr<TATensor<std::complex<double>,4>> v2)
   : ta0_(I288), ta1_(Gamma6), ta2_(v2) { }
};

class Task195 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    void compute_() override;
  public:
    Task195(std::shared_ptr<TATensor<std::complex<double>,4>> proj, std::shared_ptr<TATensor<std::complex<double>,4>> I290)
   : ta0_(proj), ta1_(I290) { }
};

class Task196 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,2>> ta2_;
    void compute_() override;
  public:
    Task196(std::shared_ptr<TATensor<std::complex<double>,4>> I290, std::shared_ptr<TATensor<std::complex<double>,2>> Gamma38, std::shared_ptr<TATensor<std::complex<double>,2>> h1)
   : ta0_(I290), ta1_(Gamma38), ta2_(h1) { }
};

class Task197 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task197(std::shared_ptr<TATensor<std::complex<double>,4>> I290, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma35, std::shared_ptr<TATensor<std::complex<double>,4>> I307)
   : ta0_(I290), ta1_(Gamma35), ta2_(I307) { }
};

class Task198 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    void compute_() override;
  public:
    Task198(std::shared_ptr<TATensor<std::complex<double>,4>> I307, std::shared_ptr<TATensor<std::complex<double>,4>> v2)
   : ta0_(I307), ta1_(v2) { }
};

class Task199 : public Task {
  protected:
    std::shared_ptr<TATensor<std::complex<double>,4>> ta0_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta1_;
    std::shared_ptr<TATensor<std::complex<double>,4>> ta2_;
    void compute_() override;
  public:
    Task199(std::shared_ptr<TATensor<std::complex<double>,4>> I290, std::shared_ptr<TATensor<std::complex<double>,4>> Gamma29, std::shared_ptr<TATensor<std::complex<double>,4>> v2)
   : ta0_(I290), ta1_(Gamma29), ta2_(v2) { }
};


}
}
}
#endif
#endif

