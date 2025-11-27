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
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        arr[st+i]=temp[i];
    }
}

void mergeSort(vector<int>&arr,int st,int end){
    int n = arr.size();

    // size = 1, 2, 4, 8, ...
    for(int size = 1; size < n; size *= 2){
        
        // প্রতিবার দুইটি 'size' ব্লক merge
        for(int st = 0; st < n; st += 2 * size){
            int mid = min(st + size - 1, n - 1);
            int en  = min(st + 2*size - 1, n - 1);

            if(mid < en)
                merge(arr, st, mid, en);
        }
    }
}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}