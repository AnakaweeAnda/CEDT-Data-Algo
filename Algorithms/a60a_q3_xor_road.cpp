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
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int dist[n];
    vector<pll> adj[n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i!=j) adj[i].push_back({j,a[i]^a[j]});

        }
    }
    fill(dist,dist+n,-1);
    bool visited[n];
    memset(visited,false,sizeof(visited));
    priority_queue<pll,vector<pll>> pq;
    dist[0] = 0;
    pq.push({dist[0],0});
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if(visited[u]) continue;
        visited[u]=true;
        for(auto [v,w] : adj[u]) {
            if(w > dist[v] && !visited[v]) {
                dist[v] = w;
                pq.push({dist[v],v});
            }
        } 
    }
    size_t ans = 0;
    for(int i=0;i<n;i++) ans += dist[i];
    cout << ans;
}
