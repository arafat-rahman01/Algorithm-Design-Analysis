#include <bits/stdc++.h>
using namespace std;

// Simple Edge structure
struct Edge {
    int to, rev;
    int cap;
};

class Graph {
public:
    int n;
    vector<vector<Edge>> adj;

    Graph(int _n) {
        n = _n;
        adj.resize(n);
    }

    void addEdge(int u, int v, int cap) {
        adj[u].push_back({v, (int)adj[v].size(), cap});
        adj[v].push_back({u, (int)adj[u].size()-1, 0}); // reverse edge
    }
};

int main() {
    // Suppose original graph has 3 nodes (0,1,2)
    // Node 1 has capacity 5 → we will split it
    int n = 4; // 0, 1_in, 1_out, 2
    Graph g(n);

    int node1_in = 1;
    int node1_out = 2;

    // Add edge between split nodes to impose capacity
    g.addEdge(node1_in, node1_out, 5); // capacity of node1

    // Add edges from original nodes
    g.addEdge(0, node1_in, INT_MAX); // 0 -> 1_in
    g.addEdge(node1_out, 3, INT_MAX); // 1_out -> 2 (or sink)

    // Print edges
    for(int u=0; u<n; u++){
        for(auto e : g.adj[u]){
            if(e.cap > 0) // show only forward edges
                cout << u << " -> " << e.to << " | cap = " << e.cap << endl;
        }
    }

    return 0;
}
