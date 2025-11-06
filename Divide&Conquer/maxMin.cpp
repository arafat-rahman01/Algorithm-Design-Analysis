#include<bits/stdc++.h>
using namespace std;

void findMaxMin(int arr[],int st,int end,int &mx,int &mn){
    if(st==end){
        mx=mn=arr[st];   //mx=mn=arr[end];
        return;
    }

    int mid=(st+end)/2;
    int lmax,lmin,rmax,rmin;
    findMaxMin(arr,st,mid,lmax,lmin);  //D-left
    findMaxMin(arr,mid+1,end,rmax,rmin);  //D-right

    mx=max(lmax,rmax);   //conquer
    mn=min(lmin,rmin);   // "  "

}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mx,mn;
    findMaxMin(arr,0,n-1,mx,mn);
    cout<<mx<<" "<<mn<<endl;
}