#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxValue=a[0];
    for(int i=0;i<n;i++){
        if(maxValue<a[i]){
            maxValue=a[i];
        }
    }
    cout<<maxValue<<endl;
}