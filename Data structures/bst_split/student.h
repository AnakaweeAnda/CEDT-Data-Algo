#ifndef __STUDENT_H_
#define __STUDENT_H_
template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  auto trav = mRoot;
  node* p = NULL;
  while(trav != NULL) {
    if(trav->data.first < val) trav = trav->right;
    else {
      p = trav;
      trav = trav->left;
    }
  }
  if(p == NULL) return result;
  node *geq[mSize];
  node *le[mSize];
  int i=0,j=0;
  if(p->left != NULL) le[i++] = p->left;
  trav = p;
  while(trav != NULL) {
    if(trav->data.first >= val) geq[j++] = trav;
    else le[i++] = trav; 
    trav = trav->parent;
  }
  for(int k=0;k<i;k++) {
    if(k-1>=0) {
    le[k-1]->parent = le[k];
    le[k]->right = le[k-1];
    }
    if(le[k]->parent != NULL && le[k]->parent->left == le[k]) le[k]->parent->left = NULL;
  }
  for(int k=0;k<j;k++) {
    if(k-1>=0) {
    geq[k-1]->parent = geq[k];
    geq[k]->left = geq[k-1];
    }
    if(geq[k]->parent != NULL && geq[k]->parent->right == geq[k]) geq[k]->parent->right = NULL;
  }

  if(i==0) mRoot = NULL;
  else {
    mRoot = le[i-1];
    le[i-1]->parent = NULL;
  }

  if(j==0) result.mRoot = NULL;
  else {
    result.mRoot = geq[j-1];
    geq[j-1]->parent = NULL;
  }
  return result;

}

#endif
