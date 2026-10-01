//https://leetcode.com/problems/product-of-array-except-self/

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int pro=1;
//     for(int i=0;i<n;i++) pro*=arr[i];
//     for(int i=0;i<n;i++) cout<<pro/arr[i]<<" ";
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++){
        int pro=1;
        for(int j=0;j<n;j++){
            if(i != j) 
                pro*=arr[j];
        }
        cout<<pro<<" ";
    }
}