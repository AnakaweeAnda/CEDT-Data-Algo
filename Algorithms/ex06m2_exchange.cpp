#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int K,n;
bool check(double R[505][505]) {
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                R[i][j] = max(R[i][j],R[i][k]*R[k][j]);
                if(R[j][j]>1) return true;
            }
        }
    }
    return false;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    while(K--) {
        cin >> n;
        double r[505][505];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> r[j][i];
            }
        }
        cout << (check(r)? "YES\n" : "NO\n");
    }
}
