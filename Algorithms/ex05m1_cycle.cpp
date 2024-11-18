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

int t,n,e;
bool isCycle = false;
bool visited[1005] = {false};
void findCycle(vector<int> A[1005],int u,int prev) {
    if(visited[u]) {
        isCycle = true;
        return;
    }
    visited[u] = true;
    for(auto v : A[u]) {
        if(v != prev) findCycle(A,v,u);
    }
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> t;
    for(int i=0;i<t;i++) {
        cin >> n >> e;
        vector<int> adj[1005];
        memset(visited,false,sizeof(visited));
        isCycle = false;
        for(int i=0;i<e;i++) {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++) {
            if(!visited[i]) findCycle(adj,i,0);
            else continue;
        }
        if(isCycle) cout << "YES\n";
        else cout << "NO\n";
    }

}
