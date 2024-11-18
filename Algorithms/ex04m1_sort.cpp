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
vector<int> original;
vector<int> sorted;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        original.push_back(a);
        sorted.push_back(a);
    }
    sort(sorted.begin(),sorted.end());
    int op1=0,op2=0;
    for(int i=0;i<n;i++) {
        if(original[i] < sorted[i]) op1++;
        else if(original[i]>sorted[i]) op2++;
    }
    cout << max(op1,op2);
}
