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

int n,k;
string bits="";
void gen() {
    if(bits.size() == n) {
        bool consec_1 = false;
        int mx = 0;
        int curr = 0;
        for(int i=0;i<n;i++) {
            if(bits[i]=='1') {
                consec_1 = true;
            }
            else consec_1 = false;
            if(consec_1) {curr++;}
            else {
                mx = max(mx,curr);
                curr = 0;
            }
        }
        mx = max(mx,curr);
        if(mx >= k) cout << bits << '\n';
        return;
   }
   bits += '0';
    gen();
    bits.pop_back();
    bits += '1';
    gen();
    bits.pop_back();
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    gen();
}
