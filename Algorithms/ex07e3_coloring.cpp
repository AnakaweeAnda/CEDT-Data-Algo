#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[55];
int n,e,c;
int color[55];
bool valid=false;
bool canColor(int u,int col) {
	for(auto v : adj[u]) {
		if(color[v] == col && color[v] != -1) return false;
	}
	return true;
}
void recurr(int u,bool &valid) {
	if(valid) return;
	if(u==n) {
		valid=true;
		return;
	}
	for(int i=0;i<c;i++) {
		if(canColor(u,i)) {
			color[u] = i;
			recurr(u+1,valid);
		}
	}
	color[u] = -1;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> e;
	
	for(int i=0;i<e;i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(color,color+n,-1);
	int l=0,r=n;
	while(l<=r) {
		int mid = (l+r)/2;
		valid = false;
		c = mid;
		recurr(0,valid);
		if(valid) {
			r = mid-1;
		}
		else l = mid+1;
	}
	cout << l ;
}
