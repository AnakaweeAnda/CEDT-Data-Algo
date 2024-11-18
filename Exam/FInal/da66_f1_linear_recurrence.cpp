#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
int a[1005];
int c[1005];
int dp[1005];
const int mod = 32717;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i=0;i<k;i++) {
        cin >> c[i+1];
    }
    for(int i=0;i<k;i++) {
        cin >> a[i];
    }
    for(int i=0;i<k;i++) {
        dp[i] = a[i];
    }
    for(int i=k;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            dp[i] += (c[j]%mod * dp[i-j]%mod)%mod;
            dp[i] %= mod;
        }
    }
    cout << dp[n];
}
