#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <bits/stdc++.h>
using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        AdjList.resize(3);
    }

    SparseGraph(int n_in) {
        AdjList.resize(n_in);
    }

    SparseGraph(const SparseGraph& G) {
        this->AdjList = G.AdjList;
    }

    void AddEdge(int a, int b) {
        AdjList[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        AdjList[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        return AdjList[a].count(b);
    }

    SparseGraph Transpose() const {
        SparseGraph result(AdjList.size());
        for(size_t i = 0 ; i<AdjList.size();i++) {
            for(auto j : AdjList[i]) {
                result.AddEdge(j,i);
            }
        }
        return result;
    }

protected:
    vector<set<int>> AdjList;
};
#endif // __SPARSE_GRAPH_H__

