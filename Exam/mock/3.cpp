#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



size_t arr[200005];
size_t n;
int m;
size_t amount(ll k) {
    size_t sum = 0;
    for(int i=1;i<=m;i++) {
        sum += (k/arr[i]);
    }
    return sum;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        cin >> arr[i];
    }
    size_t L = 1;
    size_t R = LLONG_MAX-1; 
    size_t ans;
    while(L<=R) {
        size_t mid = ((L+R)/2);
        if(amount(mid)>=n) {
            ans = mid;
            R = mid-1;
        }
        else {
            L = mid+1;
        }
    }
    cout << ans;
   
}
