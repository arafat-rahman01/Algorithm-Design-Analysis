#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int src;
    cin >> src;

    vector<bool> visited(n + 1, false);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";  // visiting

        for (int nxt : adj[node]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    return 0;
}
