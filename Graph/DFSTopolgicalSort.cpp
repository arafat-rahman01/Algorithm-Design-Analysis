#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;

    for (int v : adj[node]) {
        if (!vis[v]) {
            dfs(v, adj, vis, st);
        }
    }

    st.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;   // n = nodes, m = edges

    vector<vector<int>> adj(n);

    // directed edges input
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> vis(n, 0);
    stack<int> st;

    // disconnected graph হলেও সব node cover হবে
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    // stack থেকে pop করে topo order বানাও
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
