#include<bits/stdc++.h>
using namespace std;

int par(vector<int>&arr,int st,int end){
    int p=arr[st];
    int i=st+1;
    int j=end;

    while(true){
        while(i<=end && arr[i]<=p) i++;
        while(j>=st && arr[j]>p) j--;
        if(i<j) swap(arr[i],arr[j]);
        else break;
    }
    swap(arr[st],arr[j]);
    return j;
}

void quickSort(vector<int>&arr,int st,int end){
    if(st<end){
        int p=par(arr,st,end);
        quickSort(arr,st,p-1);
        quickSort(arr,p+1,end);
    }
}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}