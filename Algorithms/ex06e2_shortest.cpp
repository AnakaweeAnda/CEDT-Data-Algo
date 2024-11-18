#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,e,s;
vector<tuple<int,int,int>> edge;
int dist[105];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> e >> s;
    for(int i=0;i<n;i++) {
        dist[i] = 1e9;
    }
    for(int i=0;i<e;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({u,v,w});
    }
    dist[s] = 0;
    for(int i=0;i<n-1;i++) {
        for(auto [a,b,c] : edge) {
            if(dist[a]+c < dist[b]) {
                dist[b] = dist[a] + c;
            }
        }
    }
    bool isCycle = false;
    for(auto [a,b,c] : edge) {
        if(dist[a]+c < dist[b]) {
            isCycle = true;
            break;
        }
    }
    if(isCycle) {
        cout << -1;
    }
    else {
        for(int i=0;i<n;i++) {
            cout << dist[i] << ' ';
       }
    }
}
