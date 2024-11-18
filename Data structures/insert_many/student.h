#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
#include <algorithm>
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  std::sort(data.begin(),data.end());
  size_t n = mSize + data.size(); 
  T* newData = new T[n];
  int i=0,j=0,cnt=0,k=0;
  while(i < n) {
    if(i == data[j].first+cnt) {
      newData[i] = data[j].second;
      j++;
      cnt++;
    }
    else {
      newData[i] = mData[k];
      k++;
    }
    i++;
  }
  mSize = n;
  mCap = n;
  delete [] mData;
  mData = newData;
}

#endif
