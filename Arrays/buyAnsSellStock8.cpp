//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int minPrice = arr[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++){
        minPrice = min(minPrice, arr[i]);
        int profit = arr[i] - minPrice;
        maxProfit = max(maxProfit, profit);
    }
}