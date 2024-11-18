#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++) {
        int x,c; cin >> x >> c;
        for(int i=0;i<c;i++) {
            vec.push_back(x);
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<q;i++) {
        int p;
        cin >> p;
        cout << vec[p-1] <<'\n';
    }
}
