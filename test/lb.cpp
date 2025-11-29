#include<bits/stdc++.h>
using namespace std;

bool bs(vector<int>&arr,int st,int end,int key){
    if(st>end) return false;
    int mid=(st+end)/2;
    if(arr[mid]==key) return true;
    else if(arr[mid]>key) return bs(arr,st,mid-1,key);
    else if(arr[mid]<key) return bs(arr,mid+1,end,key);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    bool f=bs(arr,0,n-1,10);
    if(f) cout<<"YES";
    else cout<<"No";
    
}