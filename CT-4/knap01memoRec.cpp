#include <bits/stdc++.h>
using namespace std;

// Recursive + Memoization function
int knap(int i, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
    if (i < 0) return 0;          // No items left
    if (dp[i][w] != -1) return dp[i][w];  // Already computed (memo)

    int notTake = knap(i - 1, w, wt, val, dp);
    int take = INT_MIN;

    if (wt[i] <= w) {
        take = val[i] + knap(i - 1, w - wt[i], wt, val, dp);
    }

    dp[i][w] = max(take, notTake);
    return dp[i][w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cout << "Enter number of items (n) and capacity (W): ";
    cin >> n >> W;

    vector<int> wt(n), val(n);

    cout << "Enter " << n << " weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    // DP table (n x (W+1)) filled with -1
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    int ans = knap(n - 1, W, wt, val, dp);
    cout << "Maximum value = " << ans << "\n";

    return 0;
}
