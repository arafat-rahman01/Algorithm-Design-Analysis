#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    unordered_set<int>s;
    int target;cin>>target;
    bool flag=false;
    for(int i=0;i<n;i++){
        int cmp=target-arr[i];
        if(s.find(cmp)!=s.end()) flag = true;
        s.insert(arr[i]);
    }
    if(flag) cout<<"Found";
    else cout<<"Not Found";
}