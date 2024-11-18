#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
#include "list.h"
template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  for(auto &lst : ls) {
    if(lst.empty()) continue;
    node* st = lst.mHeader->next;
    node* fi = lst.mHeader->prev;
    st->prev = this->mHeader->prev;
    fi->next = this->mHeader;
    this->mHeader->prev->next = st;
    this->mHeader->prev = fi;
    this->mSize += lst.size();
    lst.mHeader->next = lst.mHeader;
    lst.mHeader->prev = lst.mHeader;
    lst.mSize = 0;
  }
}

#endif
