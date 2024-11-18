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

int n;
vector<pii> adj[1005];
bool visited[1005];
int dist[1005];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            int w;
            cin >> w;
            adj[i].push_back({j,w});
            adj[j].push_back({i,w});
        }
    }
    for(int i=0;i<n;i++) dist[i]=INT_MAX;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[0]=0;
    pq.push({dist[0],0});
    while(!pq.empty()) {
        auto [d,u]=pq.top();
        pq.pop();
        if(visited[u]) continue;
        visited[u]=true;
        for(auto [v,w] : adj[u]) {
            if(w < dist[v] && !visited[v]) {
                dist[v]=w;
                pq.push({dist[v],v});
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++) sum += dist[i];
    cout << sum;
}
