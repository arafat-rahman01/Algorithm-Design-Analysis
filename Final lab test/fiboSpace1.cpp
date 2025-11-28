#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==0 || n==1){
        cout<<n;
        return 0;
    }
    int p1=1,p2=0,curr=0;
    for(int i=2;i<=n;i++){
        curr=p1+p2;
        p2=p1;
        p1=curr;
    }
    cout<<curr;

}