#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n;
int dp[105][105];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<=n;i++) {
        dp[0][i]=1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i>=j) dp[i][j] = dp[i-j][j] + dp[i][j-1];
            else dp[i][j] = dp[i][j-1];
        }
    }
    cout << dp[n][n];
}
