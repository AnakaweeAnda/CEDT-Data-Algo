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
bool bits[260];
bool check(string s,bool mutated)
{
	if(s.size()==2) {
		if(s[0] == '0' && s[1] == '1') return true;
		else return false;
	}
	else if(mutated) {
		string s1 = "";
		string s2 = "";
		for(int i=s.size()/2 - 1;i>=0;i--) s1 += s[i];
		for(int i=s.size()/2;i<s.size();i++) s2 += s[i];
		return (check(s1,true) | check(s1,false)) & (check(s2,true) | check(s2,false));
	}
	else {
		string s1 = "";
		string s2 = "";
		for(int i=0;i<s.size()/2;i++) s1 += s[i];
		for(int i=s.size()/2;i<s.size();i++) s2 += s[i];
		return (check(s1,true) | check(s1,false)) & (check(s2,true) | check(s2,false));
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		string S="";
		for(int i=0;i<pow(2,k);i++) {
			char s;
			cin >> s;
			S += s;
		}
		if(check(S,true) || check(S,false)) cout << "yes\n";
		else cout << "no\n";
	}
}
