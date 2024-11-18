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

map<ll,ll> parent;
int n,m;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        ll u,v;
        cin >> u>> v;
        parent[v] = u;
    }
    for(int i=0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        if(parent[parent[a]] == 0 || parent[parent[b]] == 0 || a==b) {
            cout << "NO\n";
        }
        else if(parent[parent[a]]==parent[parent[b]]) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
