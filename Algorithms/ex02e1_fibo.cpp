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


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int dp[50]={0};
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=45;i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    int n;
    cin >> n;
    cout << dp[n];
}
