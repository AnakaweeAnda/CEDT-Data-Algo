#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"
#include <bits/stdc++.h>
template <typename T>
void CP::queue<T>::reverse() {
  mFront = (mFront + (aux?(1-mSize+mCap):(mSize-1)))%mCap;
  aux = (aux?0:1);
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  return mData[aux?(mFront+1-mSize+mCap)%mCap:(mFront+mSize-1)%mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  ensureCapacity(mSize+1);
  mData[(aux?(mFront-mSize+mCap)%mCap:(mFront+mSize)%mCap)] = element;
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  mFront = (aux? (mFront-1+mCap)%mCap:(mFront + 1) % mCap);
  mSize--;
}

#endif