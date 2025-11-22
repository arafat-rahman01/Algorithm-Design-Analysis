#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v; // u -> v
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> topoOrder;

    while(!q.empty()){
        int node = q.front(); q.pop();
        topoOrder.push_back(node);

        for(int nxt : adj[node]){
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }

    if(topoOrder.size() != n){
        cout << "Graph has a cycle!\n";
    } else {
        for(int node : topoOrder) cout << node << " ";
        cout << endl;
    }

    return 0;
}
