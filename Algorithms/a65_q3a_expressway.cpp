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

int n,w;
vector<pii> adj[705];
int dist[705];
bool visited[705]={false};
void djk_update()
{
	for(int i=1;i<=n;i++)
	{
		dist[i]=100000000;
	}
	memset(visited,false,sizeof(visited));
	dist[1]=0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({dist[1],1});
	while(!pq.empty())
	{
		auto [d,u]=pq.top();
		pq.pop();
		if(visited[u]) continue;
		visited[u]=true;
		for(auto [v,w]:adj[u])
		{
			if(dist[u]+w<dist[v] && !visited[v])
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
	cout << dist[2]  << ' ';
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n >> w;
	adj[1].push_back({2,w});
	adj[2].push_back({1,w});
	for(int i=3;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			int a,w;
			cin >> a >> w;
			adj[a].push_back({i,w});
			adj[i].push_back({a,w});
		}
		djk_update();
	}
}
