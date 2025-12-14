#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="abccccdd";
    int oddCount=0;
    unordered_map<char,int>freq;
    for(char ch:s){
        freq[ch]++;
        if(freq[ch]%2!=0){
            oddCount++;
        }else{
            oddCount--;
        }
    }
    if(oddCount>1){
        cout<<s.length()-oddCount+1;
    }
    else cout<<s.length();
}