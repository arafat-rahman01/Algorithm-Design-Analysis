#include<bits/stdc++.h>
using namespace std;

int par(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(true){
        while(i<=high && arr[i]<=pivot) i++;
        while(j>=low && arr[j]>pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
        else break;
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int>&arr,int low,int high){
    if(low<high){
        int p=par(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

}