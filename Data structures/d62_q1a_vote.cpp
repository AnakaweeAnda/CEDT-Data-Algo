#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


 map<string,int> vote;
 int n,k;
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        vote[s]++;
    }
    vector<int> votes;
    for(auto [i,j] : vote) votes.push_back(j);
    sort(votes.begin(),votes.end());
    if(votes.size()<k) cout << votes[0];
    else {
        cout << votes[votes.size()-k];
    }

}
