#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ser_val;cin>>ser_val;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==ser_val){
            flag=true;
            break;
        }
    }
    (flag)?cout<<"YES":cout<<"NO";
}