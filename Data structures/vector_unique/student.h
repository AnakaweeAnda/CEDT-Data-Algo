#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <bits/stdc++.h>
#include "vector.h"
//you can include any other file here
//you are allow to use any data structure
using namespace std;

template <typename T>
void CP::vector<T>::uniq() {
  set<T> tmp;
  for(int i=0;i<mSize;i++) {
    tmp.insert(mData[i]);
  }
  size_t n = tmp.size();
  T* newData = new T[n];
  tmp.clear();
  int j = 0;
  for(int i=0;i<mSize;i++) {
    if(tmp.count(mData[i]) == 0) {
      newData[j] = mData[i];
      j++;
      tmp.insert(mData[i]);
    }
  }
  mCap = n;
  mSize = n;
  delete [] mData;
  mData = newData;
}

#endif
