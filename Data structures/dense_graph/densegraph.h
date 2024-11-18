#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
#include <set>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        AdjList.resize(3);
        n=3;
    }

    DenseGraph(int n_in) {
        AdjList.resize(n_in);
        n=n_in;
    }

    DenseGraph(const DenseGraph& G) {
        AdjList = G.AdjList;
        n = G.n;
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

    DenseGraph Transpose() const {
        DenseGraph result(n);
        for(int i=0;i<n;i++) {
            for(auto j : AdjList[i]) result.AddEdge(j,i);
        }
        return result;
    }

protected:
    int n;
    vector<set<int>> AdjList;
};
#endif // __DENSE_GRAPH_H__
