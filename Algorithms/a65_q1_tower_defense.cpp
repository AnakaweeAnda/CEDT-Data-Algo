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

int n,m,k,w;
vi t;
vi h;
vi p;
int count_towers[100005];
int sum = 0;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n >> m >> k >> w;
	for(int i=0;i<m;i++)
	{
		int a;
		cin >> a;
		p.push_back(a);
	}
	for(int i=1;i<=m;i++)
	{
		int a;
		cin >> a;
		h.push_back(a);
	}
	for(int i=1;i<=k;i++)
	{
		int a;
		cin >> a;
		t.push_back(a);
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(t[i]-w <= p[j] && p[j]<=t[i]+w && h[j] > 0)
			{
				h[j]=max(0,h[j]-1);
				break;
			}
		}
	}
	cout << accumulate(all(h),0);
	
}
