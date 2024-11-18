#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	if(n==NULL) return -1;
    int ld = my_recur(n->left,aux);
    int rd = my_recur(n->right,aux);
    aux = std::max(aux,ld + rd+2);
    return std::max(ld,rd)+1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	if(mRoot == NULL) return -1;
    int mx = 0,ans=0;
    mx = my_recur(mRoot,ans);
    return ans;
	
}

#endif
