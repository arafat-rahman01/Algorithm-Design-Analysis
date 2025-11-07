#include<bits/stdc++.h>
using namespace std;

int crossSum(vector<int>& arr,int st,int mid,int end){
    int leftSum=INT_MIN,rightSum=INT_MIN;
    int sum=0;

    for(int i=mid;i>=st;i--){
        sum+=arr[i];
        leftSum=max(leftSum,sum);
    }

    sum=0;

    for(int i=mid+1;i<=end;i++){
        sum+=arr[i];
        rightSum=max(rightSum,sum);
    }
    return leftSum+rightSum;
}

int findMaxSubarray(vector<int>&arr,int st,int end){
    if(st==end) return arr[st];
    int mid=(st+end)/2;
    int leftMax=findMaxSubarray(arr,st,mid);
    int rightMax=findMaxSubarray(arr,mid+1,end);
    int cross=crossSum(arr,st,mid,end);

    return max({leftMax,rightMax,cross});
}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findMaxSubarray(arr,0,n-1)<<endl;
}