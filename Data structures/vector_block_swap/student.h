#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
#include <algorithm>
template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  size_t idx_a = a-this->begin();
  size_t idx_b = b-this->begin();
  if(idx_a > idx_b) std::swap(idx_a,idx_b);
  if(idx_a+m-1>= mSize || idx_b+m-1 >= mSize || idx_a+m-1>=idx_b || m<=0 || idx_a>=mSize || idx_b>=mSize) return false;
  for(int i=0;i<m;i++) {
    std::swap(*(a+i),*(b+i));
  }
  return true;
}

#endif
