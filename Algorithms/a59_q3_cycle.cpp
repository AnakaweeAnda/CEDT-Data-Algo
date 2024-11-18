#include<bits/stdc++.h>
using namespace std;
void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

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
vi adj[100005];
vector<int> cycle;
bool visited[100005]={false};
vector<int> parent;
int cycle_s,cycle_end;
void dfs(int u,int par)
{
	visited[u]=true;
	for(auto v : adj[u])
	{
		if(v == par) continue;
		if(visited[v])
		{
			cycle_s=u;
			cycle_end=v;
			return;
		}
		parent[v]=u;
		dfs(v,parent[v]);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	parent.assign(n,-1);
	dfs(0,parent[0]);
	int ans=0;
	for(int i = cycle_end ; i!=cycle_s;i=parent[i])
	{
		ans++;
	} 
	cout << ans+1;
}
