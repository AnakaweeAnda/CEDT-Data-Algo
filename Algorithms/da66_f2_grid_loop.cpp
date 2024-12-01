#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int grid[1005][1005];
bool visited[1005][1005];
int r,c,ans=0,curr_length=0,num_cycle = 0;
bool have_cycle=false;
void findCycle(int i,int j,int prev_i,int prev_j) {
    if(i<0 || i>=r || j<0 || j>=c) return;
    if(visited[i][j]) {
        ans = max(ans,curr_length);
        have_cycle = true;
        return;
    }
    visited[i][j] = true;
    curr_length++;
    if(grid[i][j]==1) {
        if(j-1>=0 && (grid[i][j-1]==3 || grid[i][j-1]==4 || grid[i][j-1]==1) && j-1 != prev_j) findCycle(i,j-1,i,j);
        if(j+1<c && (grid[i][j+1]==5 || grid[i][j+1]==6 || grid[i][j+1]==1) && j+1 != prev_j) findCycle(i,j+1,i,j);    
    }
    if(grid[i][j]==2) {
        if(i-1>=0 && (grid[i-1][j]==4 || grid[i-1][j]==5 || grid[i-1][j]==2) && i-1 != prev_i) findCycle(i-1,j,i,j);
        if(i+1<r && (grid[i+1][j]==3 || grid[i+1][j]==6 || grid[i+1][j]==2) && i+1 != prev_i) findCycle(i+1,j,i,j);    
    }
    if(grid[i][j]==3) {
        if(i-1>=0 && (grid[i-1][j]==4 || grid[i-1][j]==5 || grid[i-1][j]==2) && i-1 != prev_i)findCycle(i-1,j,i,j);
        if(j+1<c && (grid[i][j+1]==5 || grid[i][j+1]==6 || grid[i][j+1]==1) && j+1 != prev_j)findCycle(i,j+1,i,j);    
    }
    if(grid[i][j]==4) {
        if(j+1<c && (grid[i][j+1]==5 || grid[i][j+1]==6 || grid[i][j+1]==1) && j+1 != prev_j) findCycle(i,j+1,i,j);
        if(i+1<r && (grid[i+1][j]==3 || grid[i+1][j]==6 || grid[i+1][j]==2) && i+1 != prev_i)findCycle(i+1,j,i,j);    
    }
    if(grid[i][j]==5) {
        
        if(i+1<r && (grid[i+1][j]==3 || grid[i+1][j]==6 || grid[i+1][j]==2) && i+1 != prev_i) findCycle(i+1,j,i,j);
        if(j-1>=0 && (grid[i][j-1]==3 || grid[i][j-1]==4 || grid[i][j-1]==1) && j-1 != prev_j) findCycle(i,j-1,i,j);    
    }
    if(grid[i][j]==6) {
        if(i-1>=0 && (grid[i-1][j]==4 || grid[i-1][j]==5 || grid[i-1][j]==2) && i-1!= prev_i) findCycle(i-1,j,i,j);
        if(j-1>=0 && (grid[i][j-1]==3 || grid[i][j-1]==4 || grid[i][j-1]==1) && j-1!= prev_j) findCycle(i,j-1,i,j);    
    }
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!visited[i][j]) {
                curr_length=0;
                have_cycle=false;
                findCycle(i,j,-1,-1);
                if(have_cycle) {
                    num_cycle++;
                }
            }
        }
    }
    cout << num_cycle << ' ' << ans;
}
