#include "map_bst.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int Q;
	cin >> Q;

	while(Q--){

		int n;
		cin >> n;

		CP::map_bst<int ,int > bst;
		for(int i=0;i<n;i++){
			int numberToInsert;
			cin >> numberToInsert;
			bst.insert({numberToInsert, 1});
		}

		cout << bst.furthest_distance() << '\n';

	}

	CP::map_bst<int ,int > bst;
	
	bst.insert({1, 1});
	cout << bst.furthest_distance() << '\n';

	bst.clear();
	cout << bst.furthest_distance() << '\n';

	cout << "KEY: Hh2hNML73uc4e2vHnjtTtBSiNq2doiJ5\n";
}