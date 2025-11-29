#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr,int st,int end,int key){
    if(st>end) return false;
    int mid=(st+end)/2;
    if(arr[mid]==key) return true;
    else if(arr[mid]>key) return binarySearch(arr,st,mid-1,key);
    else return binarySearch(arr,mid+1,end,key);
} 

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val;cin>>val;
    if(binarySearch(arr,0,n-1,val)) cout<<"YES found";
    else cout<<"NOT Found";
}

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int key;cin>>key;
//     int st=0,end=n-1;
//     bool f=false;
//     while(st<=end){
//         int mid=(st+end)/2;
//         if(arr[mid]==key){
//             f=true;
//             break;
//         }
//         else if(arr[mid]>key){
//             end=mid-1;
//         }
//         else{
//             st=mid+1;
//         }
//     }
//     if(f) cout<<"Yes";
//     else cout<<"No"; 
// }