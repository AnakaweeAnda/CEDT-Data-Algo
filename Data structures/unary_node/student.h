#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if(ptr == NULL || (ptr->left ==NULL && ptr->right==NULL)) return 0;
  else if(ptr->left != NULL && ptr->right == NULL) return 1+process(ptr->left);
  else if(ptr->left == NULL && ptr->right != NULL) return 1+process(ptr->right);
  else return process(ptr->left) + process(ptr->right);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  if(this->mRoot==NULL) return 0;
  return process(mRoot);
}

#endif
