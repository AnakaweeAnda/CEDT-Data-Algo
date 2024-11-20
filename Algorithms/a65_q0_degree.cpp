#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int degree[5005];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int d;
            cin >> d;
            if(d==1) degree[i]++;
            mx = max(mx,degree[i]);
        } 
    }
    int deg_cnt[mx+1];
    memset(deg_cnt,0,sizeof(deg_cnt));
    for(int i=1;i<=n;i++) {
        deg_cnt[degree[i]]++;
    }
    for(int i=0;i<=mx;i++) {
        cout << deg_cnt[i] << ' ';
    }
}
