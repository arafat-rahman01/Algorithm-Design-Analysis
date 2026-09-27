#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int t;cin>>t;
    int x;
    for(x=0;x<n;x++){
        if(arr[x]==t){
            cout<<x;
            break;
        }
    }
    cout<<"-1";
    
}