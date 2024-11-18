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

int f,w,n;
vi pos_food;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> f >> w >> n;
	for(int i=0;i<f;i++)
	{
		int a;
		cin >> a;
		pos_food.push_back(a);
	}
	sort(all(pos_food));
	int ans =1;
	int curr=pos_food[0];
	while(upper_bound(all(pos_food),curr+2*w) != pos_food.end()) {
		curr = *upper_bound(all(pos_food),curr+2*w);
		ans++;
	}
	cout << ans;
}
