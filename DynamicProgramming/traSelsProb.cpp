#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    int FULL = 1 << n;
    const int INF = 1e9;

    vector<vector<int>> dp(FULL, vector<int>(n, INF));
    dp[1][0] = 0;  // শুধু 0 নম্বর শহর ভিজিট, এবং আমরা 0 শহরেই আছি

    for (int mask = 1; mask < FULL; mask++) {
        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last))) continue;

            for (int nxt = 0; nxt < n; nxt++) {
                if (mask & (1 << nxt)) continue;

                int newMask = mask | (1 << nxt);
                dp[newMask][nxt] = min(dp[newMask][nxt],
                                       dp[mask][last] + dist[last][nxt]);
            }
        }
    }

    // শেষ পর্যন্ত সব শহর ভিজিট করে আবার 0 তে ফেরা
    int ans = INF;
    for (int last = 0; last < n; last++) {
        ans = min(ans, dp[FULL - 1][last] + dist[last][0]);
    }

    cout << ans << endl;
    return 0;
}
