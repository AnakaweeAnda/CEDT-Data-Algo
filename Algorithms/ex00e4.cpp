#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int a,b;
void recurr(string s,int cnt_1) {
    if(s.size()==b && cnt_1 == a) {
        cout << s << '\n';
        return;
    }
    else if(s.size()==b && cnt_1 != a) return;
    s += "0";
    recurr(s,cnt_1);
    s.pop_back();
    s += "1";
    recurr(s,cnt_1+1);
    return;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    recurr("",0);
}
