
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"
#include <iostream>


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    if(n == NULL) return NULL
    auto node_p = *p;
    auto node_q = *q;
    if(mLess(node_p.first,n->data.first) == mLess(node_q.first,n->data.first)) {
        return (mLess(node_p.first,n->data.first) ? recursive(n->left,p,q) : recursive(n->right,p,q));
    }
    else return iterator(n);
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    return recursive(mRoot,p,q);
}

#endif
