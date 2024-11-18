#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,k;
ll c[35][35];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<=30;i++) {
        c[i][i] = 1;
        c[i][0] = 1;
    }
    for(int i=1;i<=30;i++) {
        for(int j=1;j<=30;j++) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    cin >> n >> k;
    cout << c[n][k];

}
