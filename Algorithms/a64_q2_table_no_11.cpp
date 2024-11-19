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

const int M = 1e8+7;
int dp[10000005];
int n;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n;
	dp[0]=1;
	dp[1]=3;
	for(int i=2;i<=n;i++)
	{
		dp[i] = (2*dp[i-1])%M+dp[i-2]%M;
		dp[i] %= M;	
	}
	cout << dp[n];
	
}
