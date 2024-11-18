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

int n,m;
vector<int> vec;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        int l = 0;
        int r = n-1;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(vec[mid] <= x) {
                ans = vec[mid];
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        cout << ans << '\n';
    }
}
