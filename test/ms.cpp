#include<bits/stdc++.h>
using namespace std;

int cs(vector<int>&arr,int st,int mid,int end){
    int ls=INT_MIN,rs=INT_MIN;
    int sum=0;
    for(int i=mid;i>=st;i--){
        sum+=arr[i];
        ls=max(ls,sum);
    }
    sum=0;
    for(int i=mid+1;i<=end;i++){
        sum+=arr[i];
        rs=max(rs,sum);
    }
    return ls+rs;
}

int sas(vector<int>&arr,int st,int end){
    if(st==end) return arr[st];
    int mid=(st+end)/2;
    int lm=sas(arr,st,mid);
    int rm=sas(arr,mid+1,end);
    int cross=cs(arr,st,mid,end);

    return max({lm,rm,cross});
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sas(arr,0,n-1);
}