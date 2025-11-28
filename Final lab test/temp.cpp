#include<bits/stdc++.h>
using namespace std;

// int par(vector<int>&arr,int low,int high){
//     int pivot=arr[low];
//     int i=low+1,j=high;
//     while(true){
//         while(i<=high && arr[i]<=pivot) i++;
//         while(j>=low && arr[j]>pivot)j--;
//         if(i<j) swap(arr[i],arr[j]);
//         else break;
//     }
//     swap(arr[low],arr[high]);
//     return j;  
// }

// void quickSort(vector<int>&arr,int low,int high){
//     if(low<high){
//         int p=par(arr,low,high);
//         quickSort(arr,low,p-1);
//         quickSort(arr,p+1,high);
//     }
// }

// int main(){
//     int n;cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     quickSort(arr,0,n-1);
//     for(int i=0;i<n;i++) cout<<arr[i]<<" ";
// }

int crossSum(vector<int>&arr,int st,int mid,int end){
    int ls=INT_MIN,rs=INT_MIN;
    int sum=0;
    for(int i=mid;i>=st;i--){
        sum+=arr[i];
        ls=max(sum,ls);
    }
    sum=0;
    for(int j=mid+1;j<=end;j++){
        sum+=arr[j];
        rs=max(sum,rs);
    }
    return ls+rs;
}

int subArraySum(vector<int>&arr,int st,int end){
    if(st==end) return arr[st];
    int mid=(st+end)/2;
    int lm=subArraySum(arr,st,mid);
    int rm=subArraySum(arr,mid+1,end);
    int c=crossSum(arr,st,mid,end);

    return max({lm,rm,c});
}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<subArraySum(arr,0,n-1);
}