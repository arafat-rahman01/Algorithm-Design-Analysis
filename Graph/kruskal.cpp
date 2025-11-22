#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

// Union-Find functions
int findParent(int u, vector<int> &parent) {
    if(parent[u] == u) return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionSet(int u, int v, vector<int> &parent) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    parent[pu] = pv;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for(int i=0; i<m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight ascending
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
        return a.w < b.w;
    });

    vector<int> parent(n+1);
    for(int i=1; i<=n; i++) parent[i] = i;

    int mst_weight = 0;
    vector<pair<int,int>> mst_edges;

    for(auto e : edges){
        if(findParent(e.u, parent) != findParent(e.v, parent)){
            unionSet(e.u, e.v, parent);
            mst_weight += e.w;
            mst_edges.push_back({e.u, e.v});
        }
    }

    cout << "MST Weight: " << mst_weight << endl;
    cout << "Edges in MST: ";
    for(auto p : mst_edges){
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
