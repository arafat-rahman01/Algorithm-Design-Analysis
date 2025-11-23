#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;cin>>s;
    vector<bool>visited(n+1,false);
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int nxt:adj[node]){
            if(!visited[nxt]){
                visited[nxt]=true;
                q.push(nxt);
            }
        }
    }
}