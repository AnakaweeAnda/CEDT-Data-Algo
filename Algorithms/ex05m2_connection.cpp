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

const int INF = 1000000000;
int n,e,K;
int dist[1005][1005];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> e >> K;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist[i][j] = INF; 
        }
        dist[i][i] = 0;
    }
    for(int i=0;i<e;i++) {
        int u,v;
        cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int mx = 0;
    for(int i=0;i<n;i++) {
        int curr = 0;
        for(int j=0;j<n;j++) {
            if(dist[i][j] <= K) curr++;
        }
        mx = max(curr,mx);
    }
    cout << mx;
}
