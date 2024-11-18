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

int n,m;
vector<pii> adj[25];
vector<int> mxn(26,0);
bool visited[25];
int ki[8];

void search_graph(int mx,int curr_sum,bool &found,int currNode,int GoalSum) {
	if(curr_sum > GoalSum || mx+curr_sum < GoalSum) return;
	if(curr_sum==GoalSum) {
		found=true;
		return;
	}
	visited[currNode] = true;
	for(auto [nextNode,w] : adj[currNode]) {
		if(!visited[nextNode]) search_graph(mx-mxn[nextNode],curr_sum+w,found,nextNode,GoalSum);
		if(found) return;
	}
	visited[currNode] = false;

}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n >>m ;
	for(int i=0;i<8;i++)
	{
		cin >> ki[i];
	}
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin >> a >> b >> w;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}
	int M = 0;
	for(int i=0;i<n;i++) {
		for(auto j : adj[i]) {
			mxn[i] = max(mxn[i],j.second);
		}
		M += mxn[i];
	}
	for(int i=0;i<8;i++)
	{
		bool found=false;
		for(int j=0;j<n;j++) {
			fill(visited,visited+n,false);
			if(found) break;
			if(visited[j]) continue;
			else {
				search_graph(M-mxn[j],0,found,j,ki[i]);
				 if (found) {
                cout << "YES\n";
                break;
            }
			}
		}
		if(!found) cout << "NO\n";
	}
}

