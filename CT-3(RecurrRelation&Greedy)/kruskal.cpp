#include <bits/stdc++.h>
using namespace std;

int findParent(int x, vector<int> &parent) {
    if(parent[x] == x) return x;
    return findParent(parent[x], parent); // simple version
}

void unite(int a, int b, vector<int> &parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    parent[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges; // (w, u, v)

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end()); // smallest weight first

    vector<int> parent(n);
    for(int i = 0; i < n; i++) parent[i] = i;

    int totalCost = 0;

    for(auto e : edges) {
        int w, u, v;
        tie(w, u, v) = e;

        if(findParent(u, parent) != findParent(v, parent)) {
            cout << u << " - " << v << " (cost = " << w << ")\n";
            totalCost += w;
            unite(u, v, parent); 
        }
    }

    cout << "Total Minimum Cost = " << totalCost << endl;
}
