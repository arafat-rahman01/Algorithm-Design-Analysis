#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;   // n = nodes, m = edges

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    // edges input
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v);
        indegree[v]++;   // incoming edge count
    }

    queue<int> q;

    // push all nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> topo;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int v : adj[node]) {
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }

    // Check if valid topo possible (cycle exists or not)
    if(topo.size() != n) {
        cout << "Cycle detected! Topological sort not possible.\n";
    } 
    else {
        for(int x : topo) cout << x << " ";
        cout << endl;
    }

    return 0;
}
