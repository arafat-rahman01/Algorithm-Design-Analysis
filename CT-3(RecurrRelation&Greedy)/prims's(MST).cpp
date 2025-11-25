#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // adjacency list: (node, weight)
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    vector<int> key(n, INT_MAX);   // minimum weight to connect a node
    vector<bool> used(n, false);   // node already taken in MST?
    vector<int> parent(n, -1);     // MST structure

    key[0] = 0;  // start from node 0

    for(int i = 0; i < n; i++){
        // 1. choose unused node with smallest key
        int u = -1;
        for(int j = 0; j < n; j++){
            if(!used[j] && (u == -1 || key[j] < key[u])){
                u = j;
            }
        }

        used[u] = true; // add to MST

        // 2. relax neighbours
        for(auto x : adj[u]){
            int v = x.first;
            int w = x.second;

            if(!used[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    // Print MST edges
    int totalCost = 0;
    for(int i = 1; i < n; i++){
        cout << parent[i] << " - " << i << " (cost = " << key[i] << ")\n";
        totalCost += key[i];
    }

    cout << "Total Minimum Cost = " << totalCost << endl;

    return 0;
}
