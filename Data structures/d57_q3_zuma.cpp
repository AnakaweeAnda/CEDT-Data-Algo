#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    list<int> line;
    int n,k,v;
    cin >> n >> k >> v;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        line.push_back(a);
    }
    auto it = line.begin();
    for(int i=0;i<k;i++) {
        it++;
    }
    auto itr = line.insert(it,v);
    if(itr!=line.begin() && *prev(itr) == v && (next(itr)==line.end() || *next(itr)!=v)) itr--;
    if ((itr!=line.begin() && *prev(itr) != v) && (next(itr)==line.end() || *next(itr)==v)) itr++;
    while(itr != line.end()) {
        v = *itr;
        if((itr!=line.begin() && *prev(itr)==v) && (next(itr)!=line.end() && *next(itr)==v)) {
            while(itr != line.begin() && *prev(itr)==v) line.erase(prev(itr));
            while(next(itr) != line.end() && *next(itr)==v) line.erase(next(itr));
            itr = line.erase(itr);
            if(itr == line.end() && itr != line.begin()) itr--;
        }
        else {
            break;
        }
    }
    for(auto x : line) cout << x << ' ';
}
