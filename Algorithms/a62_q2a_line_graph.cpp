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

int n,e;
vector<int> adj[100005];
bool visited[100005];
int ans = 0;
bool isLine = true;
void dfs(int u,int p) {
    if(visited[u]) {
        isLine = false;
        return;
    }
    visited[u]=true;
    if(adj[u].size() > 2) {
        isLine=false;
    }
    for(auto v : adj[u]) {
        if(v!=p) dfs(v,u);
    }
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> e;
    for(int i=0;i<e;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++) {
        if(!visited[i]) dfs(i,0);
        else continue;
        if(isLine) ans++;
        isLine=true;
    }
    cout << ans;
}
