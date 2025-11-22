#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    // undirected weighted graph
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    const long long INF = 1e18;
    vector<long long> dist(n+1, INF);

    dist[src] = 0;

    // min-heap → (distance, node)
    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    pq.push({0, src});

    while(!pq.empty()){
        long long cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(cost > dist[node]) continue;

        for(auto edge : adj[node]){
            int nxt = edge.first;
            int w   = edge.second;

            if(dist[node] + w < dist[nxt]){
                dist[nxt] = dist[node] + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    // print result
    for(int i=1; i<=n; i++){
        if(dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }

    return 0;
}
