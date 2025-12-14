#include<bits/stdc++.h>
using namespace std;

void findSub(string s,string ans,int i){
    if(s.length()==i){
        if(ans.length()==0) cout<<"null";
        else cout<<ans<<" ";
        return;
    }
    findSub(s,ans+s.charAt(i),i+1);
    findSub(s,ans,i+1);
}

int main(){
    string s;cin>>s;
    findSub(s,"",0);
}