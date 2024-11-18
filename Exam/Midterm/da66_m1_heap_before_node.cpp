#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


set<int> nodes;
int n,m;
void era(int u) {
    if(u >= n) return;
    nodes.erase(u);
    era(2*u+1);
    era(2*u+2);
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        nodes.insert(i);
    }
    era(m);
    cout << nodes.size() << '\n';
    for(auto itr = nodes.begin();itr!=nodes.end();itr++) {
        cout << *itr << ' ';
    }
}
