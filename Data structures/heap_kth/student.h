#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp>
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
    std::vector<T> vec;
    for(int i=0;i< (1<<k);i++) {
        vec.push_back(mData[i]);
    }
    std::sort(vec.begin(),vec.end(),mLess);
    return vec[vec.size()-k];
}

#endif
