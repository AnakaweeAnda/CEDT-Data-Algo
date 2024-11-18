#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    T* tmp = new T[b+1];
    for(int i=0;i<=b;i++) {
        tmp[i] = top();
        pop();
    }
    int j = 0;
    int i = b;
    while(i>=0) {
        push(tmp[i]);
        if(j<b-a+1) push(tmp[i]);
        i--;
        j++;
    }
}

#endif