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
ll val[2005];
vector<pii> adj[2005];
bool visited[2005];
int dist[2005];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> val[i];
        dist[i]=-1;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            adj[i].push_back({j,val[i]^val[j]});
            adj[j].push_back({i,val[i]^val[j]});
        }
    }
    dist[0]=0;
    priority_queue<pii,vector<pii>> pq;
    pq.push({dist[0],0});
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if(visited[u]) continue;
        visited[u]=true;
        for(auto [v,w]:adj[u]) {
            if(!visited[v] && w > dist[v]) {
                dist[v] = w;
                pq.push({dist[v],v});
            }
        }
    }
    ll sum = 0;
    for(int i=0;i<n;i++) {
        sum += dist[i];
    }
    cout << sum;
}
