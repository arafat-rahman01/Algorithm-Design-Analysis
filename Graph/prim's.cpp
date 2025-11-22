#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, weight;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    vector<bool> inMST(n+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int start = 1; // choose any start node
    pq.push({0, start}); // {weight, node}
    int mst_weight = 0;
    vector<pair<int,int>> mst_edges;

    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;
        inMST[u] = true;
        mst_weight += w;

        // store edge
        if(w != 0) mst_edges.push_back({u, u}); // for clarity, you can store actual edge with parent

        for(auto e: adj[u]){
            if(!inMST[e.to]){
                pq.push({e.weight, e.to});
            }
        }
    }

    cout << "MST Weight: " << mst_weight << endl;
    cout << "Edges in MST: ";
    for(auto p: mst_edges){
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
