#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,a;
set<int> descend;
void recurr(int a) {
    if(a >= n) return;
    descend.insert(a);
    recurr(2*a+1);
    recurr(2*a+2);
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a;
    descend.insert(a);
    recurr(a);
    cout << descend.size() << '\n';
    for(auto i : descend) cout << i << ' ';

}
