#include<bits/stdc++.h>
using namespace std;
int main(){
    class Solution {
public:
    int arrayPairSum(vector<int>& n) {
        sort(n.begin(),n.end());
        int s=0;
        for(int i=0;i<n.size();i+=2){
            s+=n[i];
        }
        return s;
    }
    };

//https://leetcode.com/problems/array-partition/?envType=problem-list-v2&envId=greedy
}