#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "priority_queue.h"
using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
    size_t rank = 0;
    
    for(int i=0;i<mSize;i++) {
        rank += mLess(mData[pos],mData[i]);
    }
    
    return rank;
}

#endif
