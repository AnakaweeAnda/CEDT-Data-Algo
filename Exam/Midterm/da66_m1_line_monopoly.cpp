#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n;
const int mx = 1e9;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<pair<int,int>> interval;
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++) {
        int op; cin >> op;
        if(op == 1) {
            int a,b;
            cin >> a >> b;
            auto itr = interval.lower_bound({a,b});
            if(itr != interval.begin()) {
                itr--;
                if(itr->second < a-1) itr++;
            } 
            while(itr != interval.end() && itr->first <= b+1) {
                a = min(itr->first,a);
                b = max(itr->second,b);
                itr = interval.erase(itr);
            }
            interval.insert({a,b});
            ans = interval.size();
            
        } else {
            cout << ans << '\n';
        }
    }
}


