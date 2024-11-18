#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

int n,a;
ll c[1005];
ll mx(ll r) {
    ll sum = 0;
    for(int i=0;i<n;i++) {
        sum += (ll)(r/c[i]);
    }
    return sum;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a;
    for(int i=0;i<n;i++) {
        cin >> c[i];
    }
    for(int i=0;i<a;i++) {
        ll x;
        cin >> x;
        ll l=0,r=1000000000000000;
        ll ans = 0;
        while(l<=r) {
            ll mid = (l+r)/2;
            if(mx(mid) >= ll(x-n)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        cout << ans << '\n';
    }
}
