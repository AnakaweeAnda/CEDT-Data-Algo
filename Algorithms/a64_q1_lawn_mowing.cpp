#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k;
vector<ll> qs;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    qs.push_back(0);
    for(int i=0;i<n;i++) {
        ll a;
        cin >> a;
        qs.push_back(qs.back()+a);
    }
    for(int i=0;i<m;i++) {
        ll L,x;
        cin >> L >> x;
        L++;
        ll ans=0,r=n,l=L;
        while(l<=r) {
            ll mid = (l+r)/2;   
            if(qs[mid]-qs[L-1]+(mid-L+1)*k <= x) {
                ans = max(ans,qs[mid]-qs[L-1]);
                l = mid+1;
            }
            else r = mid-1;
        }
        cout << ans << '\n';
    }
}
