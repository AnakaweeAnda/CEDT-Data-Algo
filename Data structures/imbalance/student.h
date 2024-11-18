// Your code here
size_t height(node* n) {
    if(n == NULL) return -1;
    if(n->left == NULL && n->right == NULL) return 0;
    size_t h = 0;
    if(n->left != NULL) h=std::max(1+height(n->left),h);
    if(n->right != NULL) h=std::max(1+height(n->right),h);
    return h;
}
size_t Imbalance(node* n) {
    return abs(height(n->left)-height(n->right));
}

void process(node *n,size_t &most,node* &ans) {
    if(n == NULL) return;
    size_t tmp = Imbalance(n);
    if(tmp > most) {
        most = tmp;
        ans = n;
    }
    else if (tmp==most) {
        if(n->data.first < ans->data.first) ans = n;
    }
    process(n->left,most,ans);
    process(n->right,most,ans);
}
KeyT getValueOfMostImbalanceNode() {
    node* ANS = mRoot;
    size_t mx = 0;
    process(mRoot,mx,ANS);
    return ANS->data.first;

}
