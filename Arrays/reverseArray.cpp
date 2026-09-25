// 2.  https://www.geeksforgeeks.org/dsa/program-to-reverse-an-array/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    int brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        brr[i]=arr[n-i-1];
    }
    
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }
}