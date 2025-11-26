#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> freq(n);
    for (int i = 0; i < n; i++) cin >> freq[i];

    // Sort initially
    sort(freq.begin(), freq.end());

    int totalCost = 0;

    while (freq.size() > 1) {
        // সবচেয়ে ছোট দুইটা নেয়া
        int a = freq[0];
        int b = freq[1];

        // এদের যোগফল
        int sum = a + b;
        totalCost += sum;

        // দুইটা remove
        freq.erase(freq.begin());
        freq.erase(freq.begin());

        // নতুন sum আবার insert
        freq.push_back(sum);

        // আবার sort
        sort(freq.begin(), freq.end());
    }

    cout << "Total cost = " << totalCost << endl;
    return 0;
}
