#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> tmp;
    v = A;
    for(auto i : A) tmp.insert(i);
    for(auto i : B) {
        if(tmp.count(i) == 0) v.push_back(i);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> tmp;
    for(auto i : B) tmp.insert(i);
    for(auto i : A) {
        if(tmp.count(i) == 1) v.push_back(i);
    }
    return v;
}
