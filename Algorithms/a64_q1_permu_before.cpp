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

int n,m;
vector<int> vec;
vi before[25];
vector<vector<int>> permu;
vector<int> curr_permu;
bool chosen[25]={false};
void permutation()
{
	if(curr_permu.size()==n)
	{
		permu.push_back(curr_permu);
		return;
	}
	for(int i=0;i<n;i++)
	{
		bool check=false;
		if(!before[i].empty())
		{
			for(auto s : before[i])
			{
				if(find(all(curr_permu),s)==curr_permu.end()) 
				{
					check=true;
					break;
				}
			}
		}
		if(check) continue;
		if(chosen[i]) continue;
		chosen[i]=true;
		curr_permu.push_back(i);
		permutation();
		curr_permu.pop_back();
		chosen[i]=false;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n>>m;
	for(int i=0;i<n;i++)
	{
		vec.push_back(i);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		before[b].push_back(a);
	}
	permutation();
	for(auto v : permu)
	{
		for(auto s : v)
		{
			cout << s << ' ';
		}
		cout << '\n';
	}
	
	
	
}
