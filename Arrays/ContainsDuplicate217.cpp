//https://leetcode.com/problems/contains-duplicate/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    bool f=false;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            f=true;
            break;
        }
    }
    if(f) cout<<"YES";
    else cout<<"NO";
}

//Leet Code
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size() - 1;i++){
//             if(nums[i]==nums[i+1]){
//                 return true;
//             }
//         }
//         return false;
//     }
// };