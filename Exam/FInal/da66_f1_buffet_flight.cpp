#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int dist[2005];
int co[2005],ci[2005];
int n,m;
vector<pair<int,int>> adj[2005];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> ci[i];
    }
    for(int i=0;i<n;i++) {
        cin >> co[i];
    }
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back({v,co[u]+ci[v]});
    }
    fill(dist,dist+n,1e9);
    dist[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dist[0],0});
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        for(auto [v,w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(dist[i] != 1e9) cout << dist[i] << ' ';
        else cout << -1 << ' ';
    }
}
