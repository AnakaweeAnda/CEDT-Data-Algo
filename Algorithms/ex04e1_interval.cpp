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
vector<pii> Class;
bool comp(pii a,pii b) {
    return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    Class.resize(n);
    for(int i=0;i<n;i++) {
        cin >> Class[i].first;
    }
    for(int i=0;i<n;i++) {
        cin >> Class[i].second;
    }
    sort(all(Class),comp);
    int curr_end = 0;
    int ans= 0;
    for(int i=0;i<n;i++) {
        if(Class[i].first >= curr_end) {
            ans++;
            curr_end = Class[i].second;
        }
    }
    cout << ans;
}
