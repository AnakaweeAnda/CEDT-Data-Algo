#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e8+7;
int dp[505][505][3];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int grid[505][505];
    int r,c; cin >> r >> c;
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=1;i<=r;i++) {
        for(int j=0;j<3;j++) {
            dp[i][1][j]= (grid[i][1]==0);
        }
    }
    int ans = 0;
    for(int j=2;j<=c;j++) {
        for(int i=1;i<=r;i++) {
            if(grid[i][j]==1) continue;
            dp[i][j][0] = (dp[i][j-1][1]%M + dp[i-1][j-1][2]%M)%M;
            dp[i][j][1] = (dp[i+1][j-1][0]%M + dp[i-1][j-1][2]%M)%M;
            dp[i][j][2] = (dp[i+1][j-1][0]%M + dp[i][j-1][1]%M)%M;
            if(j==c) {
                ans += (dp[i-1][j-1][2]%M + dp[i][j-1][1]%M + dp[i+1][j-1][0]%M)%M;
                ans %= M;
            }
        }
    }
    
    cout << ans;
}
