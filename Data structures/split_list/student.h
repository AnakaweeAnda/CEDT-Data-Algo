
void splitList(list<T>& list1, list<T>& list2) {
    if(mSize==0) return;
    node* split1 = this->mHeader;
    size_t n=this->mSize;
    size_t add1 = (n+1)/2;
    for(size_t i=0;i<add1;i++) {
        split1 = split1->next;
    }
    node* split2=split1->next;

    node* first = this->mHeader->next;
    node* last = split1;

    list1.mHeader->prev->next = first;
    first->prev = list1.mHeader->prev;
    last->next = list1.mHeader;
    list1.mHeader->prev = last;
    list1.mSize += (add1);

    if(this->mSize - add1 > 0) {
    first = split2;
    last = this->mHeader->prev;

    list2.mHeader->prev->next = first;
    first->prev = list2.mHeader->prev;
    last->next = list2.mHeader;
    list2.mHeader->prev = last;
    list2.mSize += (this->mSize-add1);
    }

    this->mHeader->next = this->mHeader;
    this->mHeader->prev = this->mHeader;
    mSize=0;
}
