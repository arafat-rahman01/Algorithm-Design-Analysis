#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order) {
    visited[node] = true;

    for(int nxt : adj[node]) {
        if(!visited[nxt]) {
            dfs(nxt, adj, visited, order);
        }
    }

    // All neighbors visited → push current node
    order.push_back(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v; // u -> v
        adj[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);
    vector<int> order;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, order);
        }
    }

    reverse(order.begin(), order.end());

    for(int node : order){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
