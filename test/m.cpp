#include<bits/stdc++.h>
using namespace std;

void me(vector<int>&arr,int st,int mid,int end){
    vector<int>temp;
    int i=st,j=mid+1;
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

void ms1(vector<int>&arr,int st,int end){
    if(st<end){
        int mid=(st+end)/2;
        ms1(arr,st,mid);
        ms1(arr,mid+1,end);
        me(arr,st,mid,end);
    }
}

void ms2(vector<int>&arr,int st,int end){
    int n=arr.size();
    for(int i=1;i<n;i*=2){
        for(int st=0;st<n;st+=2*i){
            int mid=min(st+i-1,n-1);
            int end=min(st+2*i-1,n-1);
            if(mid<end) me(arr,st,mid,end);
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ms1(arr,0,n-1);
    ms2(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}