#include <bits/stdc++.h>
using namespace std;

int memo[205][205];

// Top-Down Recursive + Memoization LCS
int LCS(string X, string Y, int i, int j) {
    // Base Case
    if (i == 0 || j == 0) return 0;

    // Memoized answer থাকলে ফেরত দাও
    if (memo[i][j] != -1) return memo[i][j];

    // যদি শেষ অক্ষর match করে
    if (X[i-1] == Y[j-1]) {
        return memo[i][j] = 1 + LCS(X, Y, i-1, j-1);
    }

    // না মিললে দুই দিকেই split করি
    int a = LCS(X, Y, i-1, j);
    int b = LCS(X, Y, i, j-1);

    return memo[i][j] = max(a, b);
}

int main() {
    string X, Y;
    cin >> X >> Y;

    memset(memo, -1, sizeof(memo));

    int n = X.size();
    int m = Y.size();

    cout << "LCS Length = " << LCS(X, Y, n, m) << endl;

    return 0;
}
