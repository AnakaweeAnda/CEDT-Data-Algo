#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int,int>> vec;
    int n,q;
    cin >> n >> q;
    int num = 0;
    for(int i=0;i<n;i++) {
        int x,c;
        cin >> x >> c;
        vec.push_back({x,c});
    }
    sort(vec.begin(),vec.end());
    vector<int> pos;
    pos.push_back(vec[0].second);
    for(int i=1;i<n;i++) {
        vec[i].second += vec[i-1].second;
        pos.push_back(vec[i].second);
    }
    for(int i=0;i<q;i++) {
        int p;
        cin >> p;
        int idx = lower_bound(pos.begin(),pos.end(),p)-pos.begin();
        cout << vec[idx].first << '\n';
    }
    
}
