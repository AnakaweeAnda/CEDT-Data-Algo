#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"

template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
    mSize += (last-first);
    size_t pos = position - (begin());
    T* newData = new T[mSize];
    for(int i=0;i<pos;i++) {
      newData[i] = mData[i];
    }
    for(auto it = first ; it != last ; it++) {
      newData[pos] = *it;
      pos++;
    }
    for(int i=pos;i<mSize;i++) {
      newData[i] = mData[i-(last-first)];
    }
    mCap = mSize;
    delete [] mData;
    mData = newData;
}

#endif
