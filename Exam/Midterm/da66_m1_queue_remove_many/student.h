#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  sort(pos.begin(),pos.end());
  std::vector<T> result;
  size_t i=0,j=0;
  while(i<mSize) {
    if(i==pos[j]) {
      j++;
    }
    else {
      result.push_back(mData[(mFront+i)%mCap]);
    }
    i++;
  }
  for(int i=0;i<mSize-pos.size();i++) {
    mData[(i)%mCap] = result[i];
  }
  mFront = 0;
  mSize -= pos.size();
  mCap = mSize;
}

#endif
