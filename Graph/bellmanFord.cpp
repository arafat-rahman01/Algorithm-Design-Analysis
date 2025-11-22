#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for(int i=0; i<m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    const int INF = 1e9;
    vector<int> dist(n+1, INF);
    dist[src] = 0;

    // Step 1: relax edges n-1 times
    for(int i=1; i<=n-1; i++){
        for(auto e : edges){
            if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Step 2: check negative cycle
    bool negativeCycle = false;
    for(auto e : edges){
        if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]){
            negativeCycle = true;
            break;
        }
    }

    if(negativeCycle){
        cout << "Graph contains negative weight cycle\n";
    } else {
        for(int i=1; i<=n; i++){
            if(dist[i] == INF) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
