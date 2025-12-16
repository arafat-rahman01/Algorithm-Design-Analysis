#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp(n, vector<long long>(m, 0));

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;

            long long up = (i > 0) ? dp[i-1][j] : 0;
            long long left = (j > 0) ? dp[i][j-1] : 0;

            dp[i][j] = up + left;
        }
    }
    cout << dp[n-1][m-1];
}
