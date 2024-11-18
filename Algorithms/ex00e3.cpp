#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


unordered_set<int> func;
int n;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        int a;
        cin >> a;
        func.insert(a);
    }
    bool valid = true;
    for(int i=1;i<=n;i++) {
        if(func.find(i)==func.end()) {
            valid = false;
            cout << "NO\n";
            break;
        }
    }
    if(valid) cout << "YES\n";
}
