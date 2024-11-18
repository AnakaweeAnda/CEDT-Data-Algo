#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool b[15][15];
int n;
int ans = 0;
bool canPlace(int r,int c,bool board[15][15]) {
    for(int i=r-1;i>=0;i--) if(board[i][c]) return false;
    for(int i=r+1;i<n;i++) if(board[i][c]) return false;
    for(int i=c-1;i>=0;i--) if(board[r][i]) return false;
    for(int i=c+1;i<n;i++) if(board[r][i]) return false;
    int i=r,j=c;
    while(i<n&&j<n) {
        if(board[i++][j++]) return false;
    }
    i=r,j=c;
    while(i<n&&j>=0) {
        if(board[i++][j--]) return false;
    }
    i=r,j=c;
    while(i>=0&&j>=0) {
        if(board[i--][j--]) return false;
    }
    i=r,j=c;
    while(i>=0&&j<n) {
        if(board[i--][j++]) return false;
    }
    return true;
}
void recurr(int r) {
    if(r==n) {
        ans++;
        return;
    }
    for(int i=0;i<n;i++) {
        if(canPlace(r,i,b)) {
            b[r][i] = 1;
            recurr(r+1);
            b[r][i]=0;
        }
    }

}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    recurr(0);
    cout << ans;
}
