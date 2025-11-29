#include<bits/stdc++.h>
using namespace std;

int crossSum(vector<int>&arr,int st,int mid,int end){
    int lsum=INT_MIN,rsum=INT_MIN,sum=0;
    for(int i=mid;i>=st;i--){
        sum+=arr[i];
        lsum=max(lsum,sum);
    }
    sum=0;
    for(int i=mid+1;i<end;i++){
        sum+=arr[i];
        rsum=max(rsum,sum);
    }
    return lsum+rsum;

}

int subArraySum(vector<int>&arr,int st,int end){
    int mid=(st+end)/2;
    int lmax=subArraySum(arr,st,mid);
    int rmax=subArraySum(arr,mid+1,end);
    int cross=crossSum(arr,st,mid,end);

    return max({lmax,rmax,cross});

}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    subArraySum(arr,0,n-1);
}