#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,m;
vector<int> a;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++) {
        int l = 0;
        int r = n-1;
        int target;
        cin >> target;
        bool valid = false;
        while(l<r) {
            if(a[l]+a[r] == target) {
                cout << "YES\n";
                valid = true;
                break;
            }
            else if(a[l]+a[r] < target) l++;
            else r--;
        }
        if(!valid) cout << "NO\n";
    }
}
