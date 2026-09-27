#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int m;cin>>m;
    sort(arr,arr+n);
    cout<<arr[m-1] - arr[0];
}