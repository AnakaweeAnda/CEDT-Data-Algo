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

int n;
int mat[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> mat[i][j];
			if(mat[i][j]==-1) mat[i][j] = 1000000000; 
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(k!=i && k!=j) mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
			}
		}
	}
	int ans = -1;
	bool valid = false;
	for(int i=2;i<=n;i++) {
		if(mat[1][i]!=1000000000) {
			ans = max(ans,mat[1][i]);
		}
		else {
			cout << -1 ;
			valid = true;
			break;
		}
	}
	if(!valid) cout << ans;

}
