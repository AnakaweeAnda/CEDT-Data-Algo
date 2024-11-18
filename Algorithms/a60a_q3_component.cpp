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

int n,e;
vi adj[10005];
bool visited[10005]={false};
int num_cc=0;
void dfs(int i)
{
	if(visited[i]) return;
	visited[i]=true;
	for(auto j : adj[i])
	{
		dfs(j);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n >> e;
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i]) 
		{
			dfs(i);
			num_cc++;
		}
	}
	cout << num_cc;

}
