#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.length();
    unordered_map<char,int>freq;
    for(char c:s){
        freq[c]++;
    }
    // for(auto i:freq){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    
    for(auto i:freq){
        if(i.second%2==0){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
    for(auto i:freq){
        if(i.second%2!=0){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
}