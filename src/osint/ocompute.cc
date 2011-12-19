//
// Author: Toru Shiozaki
// Date  : May 2009
//

#include <src/osint/overlapbatch.h>
#include <src/rysint/carsphlist.h>
#include <src/rysint/macros.h>
#include <cassert>
#include <cstring>
#include <iostream>
#include <src/stackmem.h>

using namespace std;

extern StackMem* stack;

void OverlapBatch::compute() {

  double* intermediate_p = stack->get(prim0_ * prim1_ * asize_);
  perform_VRR(intermediate_p);

  double* intermediate_c = stack->get(cont0_ * cont1_ * asize_);
  fill(intermediate_c, intermediate_c + cont0_ * cont1_ * asize_, 0.0);
  perform_contraction(asize_, intermediate_p, prim0_, prim1_, intermediate_c, 
                      basisinfo_[0]->contractions(), basisinfo_[0]->contraction_ranges(), cont0_, 
                      basisinfo_[1]->contractions(), basisinfo_[1]->contraction_ranges(), cont1_);

  double* intermediate_fi = stack->get(cont0_ * cont1_ * asize_intermediate_);

  if (basisinfo_[1]->angular_number() != 0) { 
    const int hrr_index = basisinfo_[0]->angular_number() * ANG_HRR_END + basisinfo_[1]->angular_number();
    hrr_.hrrfunc_call(hrr_index, cont0_ * cont1_, intermediate_c, AB_, intermediate_fi);
  } else {
    const unsigned int array_size = cont0_ * cont1_ * asize_intermediate_;
    ::memcpy(intermediate_fi, intermediate_c, array_size * sizeof(double)); 
  }

  if (spherical_) {
    struct CarSphList carsphlist;
    double* intermediate_i = stack->get(cont0_ * cont1_ * asize_final_);
    const unsigned int carsph_index = basisinfo_[0]->angular_number() * ANG_HRR_END + basisinfo_[1]->angular_number();
    const int nloops = cont0_ * cont1_;
    carsphlist.carsphfunc_call(carsph_index, nloops, intermediate_fi, intermediate_i); 

    const unsigned int sort_index = basisinfo_[1]->angular_number() * ANG_HRR_END + basisinfo_[0]->angular_number();
    sort_.sortfunc_call(sort_index, data_, intermediate_i, cont1_, cont0_, 1, swap01_);
    stack->release(cont0_ * cont1_ * asize_final_);
  } else {
    const unsigned int sort_index = basisinfo_[1]->angular_number() * ANG_HRR_END + basisinfo_[0]->angular_number();
    sort_.sortfunc_call(sort_index, data_, intermediate_fi, cont1_, cont0_, 1, swap01_);
  }

  stack->release(prim0_ * prim1_ * asize_ + cont0_ * cont1_ * asize_ + cont0_ * cont1_ * asize_intermediate_);

}

