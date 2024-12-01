#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int M = 1e9+7;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        dp[i] = (dp[i-1]%M);
        if(i-2>=0) dp[i] += ((2*(dp[i-2]%M))%M);
        dp[i] %= M;
    }
    cout << dp[n];
}
