#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
    if(n==NULL) return 0;
    if(n->left == NULL && n->right==NULL) return 1;
    size_t left_tree = 0;
    size_t right_tree = 0;
    if(n->left != NULL) left_tree = leaves_count(n->left);
    if(n->right != NULL) right_tree = leaves_count(n->right);
    return left_tree+right_tree;
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  return leaves_count(mRoot);
  //write your code here
}


#endif
