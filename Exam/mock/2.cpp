#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int grid[2005][2005];
int dist[2005][2005];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pii> treasure;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> grid[i][j];
            dist[i][j]=1e9;
            if(grid[i][j]==2) treasure.push_back({i,j});
        }
    }
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    dist[0][0] = 0;
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    pq.push({dist[0][0],{0,0}});
    while(!pq.empty()) {
        auto [d,p] = pq.top();
        auto [r,c] = p;
        pq.pop();
        for(int i=0;i<4;i++) {
            int nr = r + direction[i][0];
            int nc = c + direction[i][1];
            if(nr<0 || nr >= n || nc<0 || nc>=m) continue;
            if(grid[nr][nc]==0) continue;
            if(d+1 < dist[nr][nc]) {
                dist[nr][nc] = d+1;
                pq.push({dist[nr][nc],{nr,nc}});
            }
        }
    }
    int ans = 0;
    for(auto [r,c] : treasure) {
        ans += dist[r][c];
    }
    cout << ans*2;
}
