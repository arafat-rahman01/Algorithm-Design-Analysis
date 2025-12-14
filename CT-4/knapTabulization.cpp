#include <bits/stdc++.h>
using namespace std;

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

    // dp[i][w] = best value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Bottom-Up fill
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            int notTake = dp[i - 1][w];
            int take = 0;

            if (wt[i - 1] <= w) {
                take = val[i - 1] + dp[i - 1][w - wt[i - 1]];
            }

            dp[i][w] = max(take, notTake);
        }
    }

    cout << "Maximum value = " << dp[n][W] << "\n";
    return 0;
}
