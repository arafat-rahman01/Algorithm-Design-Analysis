#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weight(n+1), value(n+1);

    for(int i=1; i<=n; i++){
        cin >> weight[i] >> value[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<=n; i++){
        for(int w=1; w<=W; w++){
            // option 1: না নেওয়া
            dp[i][w] = dp[i-1][w];

            // option 2: নেওয়া সম্ভব হলে
            if(weight[i] <= w){
                dp[i][w] = max(dp[i][w],
                               value[i] + dp[i-1][w - weight[i]]);
            }
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}
