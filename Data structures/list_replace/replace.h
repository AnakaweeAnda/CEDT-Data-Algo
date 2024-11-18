void replace(const T& x, list<T>& y) {
  if(this->mSize == 0) return;
  auto it = this->begin();
  size_t cnt = 0;
  while(it != this->end()) {
    if(*it != x) it++;
    else {
      for(auto &i : y) {
        this->insert(it,i);
      }
      this->erase(it);
      it++;
    }
  }
  this->mSize += cnt*(y.mSize-1);

}
