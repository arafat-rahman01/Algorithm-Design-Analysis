#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr,int st,int end,int val){
    if(st<=end){
        int mid=(st+end)/2;
        if(arr[mid]==val) return mid;
        else if(arr[mid]>val) return binarySearch(arr,st,mid-1,val);
        else return  binarySearch(arr,mid+1,end,val);
    }
    return -1;
    
}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val;cin>>val;
    int find=binarySearch(arr,0,n-1,val);
    if(find!=-1) cout<<"YES"<<endl;
    else cout<<"No"<<endl;
}