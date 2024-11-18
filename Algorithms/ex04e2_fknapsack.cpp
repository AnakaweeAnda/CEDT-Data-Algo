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

double w;
int n;
vector<pair<double,double>> things(100005,{0,0});
bool comp(pair<double,double> &a , pair<double,double> &b)
{
	return a.first/a.second > b.first/b.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> w >> n;
	for(int i=0;i<n;i++)
	{
		cin >> things[i].first;
	}
	for(int i=0;i<n;i++)
	{
		cin >> things[i].second;
	}
	int i=0;
	double ans = 0;
	sort(things.begin(),things.begin()+n,comp);
	for(int i=0;i<n;i++)
	{
		if(w<=0) break;
		auto [v,W]=things[i];
		if(w-W>=0)
		{
			ans += v;
			w -= W;
		}
		else
		{
			ans += w/W*(v);
			w -= (w/W)*W;
		}
	}
	cout << setprecision(4) << fixed << ans;
}
