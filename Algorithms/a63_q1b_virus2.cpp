#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool diff(string a,string b) {
    int no1a=0;
    int no1b=0;
    for(auto i : a) if(i=='1') no1a++;
    for(auto i : b) if(i=='1') no1b++;
    return abs(no1a-no1b)<=1;
}
bool check(string a) {
    if(a.size()==2) return true;
    string b = a.substr(a.size()/2);
    a.resize(a.size()/2);
    if(diff(a,b)) return check(a)&&check(b);
    return false;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        string s;
        for(int i=0;i<(1<<k);i++) {
            char d;
            cin >> d;
            s += d;
        }
        cout << (check(s)? "yes\n":"no\n");
    }
}
