#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int minValue=a[0];
    for(int i=0;i<n;i++){
        if(minValue>a[i]){
            minValue=a[i];
        }
    }
    cout<<minValue<<endl;
}