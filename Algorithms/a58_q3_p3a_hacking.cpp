#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
vector<int> adj[50005];
int hack_time[50005];
int dist[50005];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        dist[i] = 1000000000;
    }
    vector<int> source;
    for(int i=0;i<k;i++) {
        int x;
        cin >> x;
        source.push_back(x);
    }
    for(int i=0;i<n;i++) {
        cin >> hack_time[i];
    }
    for(auto x:source) {
        dist[x] = hack_time[x];
        pq.push({dist[x],x});
    }
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        for(auto v:adj[u]) {
            if(dist[v] > dist[u]+hack_time[v]) {
                dist[v] = dist[u]+hack_time[v];
                pq.push({dist[v],v});
            }
        }
    }
    cout << *max_element(dist,dist+n);
    
}