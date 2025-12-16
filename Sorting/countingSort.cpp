#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    map<int,int>freq;
    for(int i:arr){
        freq[i]++;
    }
    int idx=0;
    for(auto i:freq){
        while(i.second--){
            arr[idx]=i.first;
        }
    }
    for(int i:arr){
        cout<<i<<" ";
    }
}