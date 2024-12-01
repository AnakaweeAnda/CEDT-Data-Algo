#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[1005];
    int dist[1005];
    bool visited[1005];
    fill(dist,dist+n+1,1e9);
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin >> w>>u >> v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dist[1],1});
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [v,w] : adj[u]) {
            if(w < dist[v] && !visited[v]) {
                dist[v] = w;
                pq.push({dist[v],v});
            }   
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans += dist[i];
    }
    cout << ans;
}
