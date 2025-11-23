#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>id(n),d(n),p(n);
    for(int i=0;i<n;i++){
        cin>>id[i]>>d[i]>>p[i];
    }
    vector<pair<int,pair<int,int>>>jobs;
    for(int i=0;i<n;i++){
        jobs.push_back({p[i],{d[i],id[i]}});
    }
    sort(jobs.rbegin(),jobs.rend());

    int maxD=0;
    for(auto &j:jobs){
        maxD=max(maxD,j.second.first);
    }
    vector<int>slot(maxD+1,-1);
    int t=0;

    for(auto &j:jobs){
        for(int d=j.second.first;d>0;d--){
            if(slot[d]==-1){
                slot[d]=j.second.second;
                t+=j.first;
                break;
            }
        }
    }

    for(int i=1;i<=maxD;i++){
        if(slot[i]!=-1) cout<<slot[i]<<endl;
    }
    cout<<t<<endl;

}