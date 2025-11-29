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
//     int n;cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int key;cin>>key;
//     bool f=false;
//     int st=0,end=n-1;
//     for(int i=0;i<n;i++){
//         int mid=(st+end)/2;
//         if(arr[mid]==key){
//             f=true;
//         }else if(arr[mid]>key){
//             end=mid;
//         }else{
//             st=mid+1;
//         }
//     }
//     if(f)cout<<"Found";
//     else cout<<"No";
// }