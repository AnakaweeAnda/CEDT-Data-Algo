#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,m,k;
vector<int> vec;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(begin(vec),end(vec));
    for(int i=0;i<m;i++) {
        int p;
        cin >> p;
        int left = lower_bound(begin(vec),end(vec),p-k)-begin(vec);
        int right = upper_bound(begin(vec),end(vec),p+k)-begin(vec);
        cout << right-left << ' ';
    }
}
