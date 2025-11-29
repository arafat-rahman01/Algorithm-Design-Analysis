#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int st,int mid,int end){
    int i=st,j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    
}

void mergeSort(vector<int>&arr,int st,int end){
    if(st<end){
        int mid=(st+end)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
}