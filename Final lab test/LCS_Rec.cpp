#include <bits/stdc++.h>
using namespace std;

// Function to return LCS length of s1[0..i-1] and s2[0..j-1]
int LCS(string &s1, string &s2, int i, int j) {
    if(i == 0 || j == 0) return 0;  // base case: empty string

    if(s1[i-1] == s2[j-1])  // last character match
        return 1 + LCS(s1, s2, i-1, j-1);
    else                     // last character not match
        return max(LCS(s1, s2, i-1, j), LCS(s1, s2, i, j-1));
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    cout << LCS(s1, s2, n, m);
    return 0;
    // Normal recursion: O(2^(n+m)) → exponential
    // Space complexity: O(n+m) → recursion stack depth
}
