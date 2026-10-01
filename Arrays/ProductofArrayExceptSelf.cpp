#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n]; int brr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int pro=1;
    for(int i=0;i<n;i++) pro*=arr[i];
    for(int i=0;i<n;i++) cout<<pro/arr[i]<<" ";
}