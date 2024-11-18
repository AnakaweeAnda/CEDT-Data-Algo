#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  for(int i=a;i<=(a+b)/2;i++) {
    swap(mData[(mFront+i)%mCap],mData[(mFront+b+a-i)%mCap]);
  }
}

#endif
