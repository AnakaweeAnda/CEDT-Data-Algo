#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int board[5005][5005];
int R,C;
int dist[5005][5005];
int dir[4] = {0,0,-1,1};
int dic[4] = {-1,1,0,0};
vector<pair<int,int>> second_country;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cin >> board[i][j];
            dist[i][j] = 1000000000;
            if(board[i][j] == 1) {
                dist[i][j]=1;
                pq.push({dist[i][j],i,j});
            }
            if(board[i][j] == 2) second_country.push_back({i,j});
        }
    }
    while(!pq.empty()) {
        auto [d,r,c] = pq.top();
        pq.pop();
        for(int i=0;i<4;i++) {
            int nr = r + dir[i];
            int nc = c + dic[i];
            if(nr < 1 || nr > R || nc<1 || nc > C) continue;
            if(board[nr][nc] == 3) continue;
            if(dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                pq.push({dist[nr][nc],nr,nc});
            }
        }
    }
    int ans = INT_MAX;
    for(auto [a,b] : second_country) {
        ans = min(dist[a][b],ans);
    }
    cout << ans;
}
