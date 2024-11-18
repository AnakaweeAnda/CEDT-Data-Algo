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

int n;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int qs[2005];
    cin >> n;
    fill(qs,qs+2*(n+1),-1e9);
    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int a;
            cin >> a;
            int idx = i-j+n-1;
            qs[idx] = max(a,qs[idx]+a);
            ans = max(ans,qs[idx]);
        }
    }
    cout << ans;

}
