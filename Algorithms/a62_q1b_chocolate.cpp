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

int n,k;
int dp[1005]={0};
vector<int> s;
const int m = 1e6+3;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n >> k;
	for(int i=0;i<k;i++)
	{
		int a;
		cin >> a;
		s.pb(a);
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(auto j : s)
		{
			if(i-j>=0) dp[i]+=(dp[i-j])%m;
			dp[i] %= m;
		}
	}
	cout << dp[n];
}
