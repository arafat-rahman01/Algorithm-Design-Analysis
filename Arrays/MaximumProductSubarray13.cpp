//https://leetcode.com/problems/maximum-product-subarray/description/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int mx=arr[0];
    int mn=arr[0];
    int ans=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]<0) swap(mx,mn);

        mx = max(arr[i], mx *arr[i]);
        mn = min(arr[i], mn * arr[i]);

        ans = max(ans, mx);
    }
    cout<<ans;
}