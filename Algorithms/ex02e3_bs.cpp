#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a; cin >> a;
        vec.push_back(a);
    }
    for(int i=0;i<m;i++) {
        int q; cin >> q;
        int l = 0;
        int r = n-1;
        int ans;
        while(l<=r) {
            int mid = (l+r)/2;
            if(vec[mid]<=q) {
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        if(q < vec[0]) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}
