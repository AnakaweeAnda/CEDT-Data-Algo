#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


set<pair<int,int>> year;
int n,m;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int y,m;
        cin >> y >> m;
        year.insert({y,m});
    }
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        if(year.upper_bound({a,b}) == year.begin()) cout << -1 << ' ' << -1 << ' ';
        else {
            auto itr = year.upper_bound({a,b});
            itr--;
            if(itr->first == a && itr->second == b) cout << 0 << ' ' << 0 << ' ';
            else {
                cout << itr->first << ' ' << itr->second << ' ';
            } 
        }

    }
}
