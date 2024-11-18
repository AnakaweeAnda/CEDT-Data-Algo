#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,k;
vector<int> mat;
vector<int> matrix_multiply(vector<int> M,vector<int> N,int k) {
    vector<int> result;
    result.resize(4);
    result[0] = ((M[0]%k*N[0]%k)%k + (M[1]%k*N[2]%k)%k)%k;
    result[1] = ((M[0]%k*N[1]%k)%k + (M[1]%k*N[3]%k)%k)%k;
    result[2] = ((M[2]%k*N[0]%k)%k + (M[3]%k*N[2]%k)%k)%k;
    result[3] = ((M[2]%k*N[1]%k)%k + (M[3]%k*N[3]%k)%k)%k;
    return result;
}
vector<int> recurr(vector<int> M,int n) {
    if(n==1) return M;
    vector<int> N = recurr(M,n/2);
    N = matrix_multiply(N,N,k);
    if(n%2 == 1) N = matrix_multiply(N,mat,k);
    return N;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    mat.resize(4);
    cin >> n >> k >> mat[0] >> mat[1] >> mat[2] >> mat[3];
    mat = recurr(mat,n);
    for(int i=0;i<4;i++) cout << mat[i] << ' ';
}
