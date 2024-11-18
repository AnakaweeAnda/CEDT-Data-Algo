#include<bits/stdc++.h>
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

int R,C;
int city[500][500];
int dp[500][500];
int visited[500][500];
int dirR[4]={0,0,1,-1},dirC[4]={1,-1,0,0};
void djk() {
    dp[1][1]=0;
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    pq.push({dp[1][1],{1,1}});
    while(!pq.empty()) {
        auto [cost,pos] = pq.top();
        pq.pop();
        int r = pos.first,c=pos.second;
        if(visited[r][c]) continue;
        visited[r][c]=true;
        for(int i=0;i<4;i++) {
            int new_r = r + dirR[i];
            int new_c = c + dirC[i];
            if(new_r < 1 || new_r > R || new_c < 1 || new_c > C) continue;
            if(dp[new_r][new_c] > dp[r][c]+city[new_r][new_c] && !visited[new_r][new_c]) {
                dp[new_r][new_c] = dp[r][c]+city[new_r][new_c];
                pq.push({dp[new_r][new_c],{new_r,new_c}});
            }
        }
    }
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> R >> C;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cin >> city[i][j];
            dp[i][j]=1000000;
        }
    }
    djk();
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
