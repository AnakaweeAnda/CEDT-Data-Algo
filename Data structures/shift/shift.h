void shift(int k) {
	if(k==0) return;
	if(k<0) {
		k = -k;
		for(int i=0;i<k;i++) {
			mHeader->data = mHeader->prev->data;
			mHeader = mHeader->prev;
			mHeader->data = 0;
		}
	}
	else {
		for(int i=0;i<k;i++) {
			mHeader->data = mHeader->next->data;
			mHeader = mHeader->next;
			mHeader->data = 0;
		}
	}


}
