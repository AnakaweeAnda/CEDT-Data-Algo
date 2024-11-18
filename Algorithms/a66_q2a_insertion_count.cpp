#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
vector<int> vec;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    for(int i=0;i<m;i++) {
        int k;
        cin >> k;
        int idx = find(vec.begin(),vec.end(),k)-vec.begin();
        int ans = 0;
        for(int j=0;j<idx;j++) {
            if(vec[j] > k) ans++;
        }
        cout << ans << '\n';
    }
}
