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

int r,c,t;
int grid[505][505];
bool visited[505][505];
int dist[505][505];
int dirR[] = {0,0,-1,1};
int dirC[] = {-1,1,0,0};
vector<pii> infect;
void djk() {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            dist[i][j] = INT_MAX;
        }
    }
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    sort(all(infect));
    for(int i=0;i<infect.size();i++) {
        auto [u,v] = infect[i];
        dist[u][v] = 0;
        pq.push({dist[u][v],{u,v}});
    }
    while(!pq.empty()) {
        auto [d,p] = pq.top();
        pq.pop();
        auto [R,C] = p;
        if(visited[R][C]) continue;
        visited[R][C] = true;
        for(int i=0;i<4;i++) {
            int Rnew = R + dirR[i];
            int Cnew = C + dirC[i];
            if(Rnew < 0 || Rnew >= r || Cnew < 0 || Cnew >= c || grid[Rnew][Cnew]==2) continue;
            if(!visited[Rnew][Cnew] && dist[Rnew][Cnew] > dist[R][C]+1) {
                dist[Rnew][Cnew] = dist[R][C]+1;
                pq.push({dist[Rnew][Cnew],{Rnew,Cnew}});
            } 
        }
    }
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> r >> c >> t;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> grid[i][j];
            if(grid[i][j]==1) {infect.push_back({i,j});}
        }
    }
    djk();
    int ans = 0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(dist[i][j] <= t) ans++;
        }
    }
    cout << ans;
}
