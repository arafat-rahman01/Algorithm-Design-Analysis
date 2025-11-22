#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int nxt : adj[node]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int src;
    cin >> src;

    dfs(src);

    return 0;
}
