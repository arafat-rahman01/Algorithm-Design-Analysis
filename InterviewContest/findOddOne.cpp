#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==1){
        cout<<arr[0];
        return 0;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            i++;
        }else{
            cout<<arr[i];
            return 0;
        }
    }
}