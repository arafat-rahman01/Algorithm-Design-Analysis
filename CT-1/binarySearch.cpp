#include<bits/stdc++.h>
using namespace std;
string binarySearch(int arr[],int st,int end,int val){
    if(st>end) return "NO";
    int mid=st+(end-st)/2;
    if(arr[mid]==val) return "YES";
    else if(arr[mid]>val){
        return binarySearch(arr,st,mid-1,val);
    }
    else return binarySearch(arr,mid+1,end,val);
}
int main(){
    int n;cin>>n;
    int arr[n];
    int val;cin>>val;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<binarySearch(arr,0,n-1,val);
}