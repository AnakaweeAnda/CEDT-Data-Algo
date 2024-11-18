#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> money;
vector<pair<int,int>> change;
int n,m,start;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> start;
    for(int i=0;i<n;i++) {
        int a,s;
        cin >> a >> s;
        change.push_back({a,s});
    }
    sort(begin(change),end(change));
    int j = 0;
    int i = 0;
    int curr_money = start;
    while(i<=100005) {
        if(n!=0) {
        if(i==change[j].first) {
            curr_money = change[j].second;
            j++;
        }
        }
        if(i==0) money.push_back(curr_money);
        else money.push_back(money.back()+curr_money);
        i++;
    }
    for(int i=0;i<m;i++) {
        int P,x;
        cin >> P >> x;
        int ans1 = lower_bound(begin(money)+x+1,end(money),P+money[x])-begin(money);
        int ans2 = lower_bound(begin(money),begin(money)+x+1,P)-begin(money);
        if(money[x] < P) cout << ans1 << ' ';
        else cout << ans2 << ' ';
        
    }

}
