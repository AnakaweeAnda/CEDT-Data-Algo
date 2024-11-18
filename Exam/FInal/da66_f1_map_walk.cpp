#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool board[12][12];
bool visited[12][12];
int R,C;
void recurr(string command , int curr_row,int curr_column) {
    if(curr_row < 1 || curr_row > R || curr_column < 1 || curr_column > C) return;
    if(board[curr_row][curr_column] || visited[curr_row][curr_column]) return;
    if(curr_row == R && curr_column == C) {
        cout << command << '\n';
        return;
    }
    visited[curr_row][curr_column] = true;
    recurr(command+"A",curr_row,curr_column+1);
    recurr(command+"B",curr_row+1,curr_column);
    recurr(command+"C",curr_row-1,curr_column);
    visited[curr_row][curr_column] = false;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cin >> board[i][j];
        }
    }
    recurr("",1,1);
    cout << "DONE";
}
