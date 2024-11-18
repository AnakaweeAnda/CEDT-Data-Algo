#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int a,b;
void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right) {
    if(a==0) {
        v[top][left] = b;
        return;
    }
    recur(v,a-1,b,top,(top+bottom)/2,left,(left+right)/2);
    recur(v,a-1,b-1,top,(top+bottom)/2,(left+right)/2,right);
    recur(v,a-1,b+1,(top+bottom)/2,bottom,left,(left+right)/2);
    recur(v,a-1,b,(top+bottom)/2,bottom,(left+right)/2,right);
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    vector<vector<int>> vec(1<<a,vector<int>(1<<a,0));
    recur(vec,a,b,0,1<<a,0,1<<a);
    for(auto i : vec) {
        for(auto j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
