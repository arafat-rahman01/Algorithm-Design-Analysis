// 22 https://www.geeksforgeeks.org/dsa/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/

#include <bits/stdc++.h>
using namespace std;
bool compare(string a, string b) {
    return a + b > b + a;
}
int main() {
    int n; cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), compare);
    for (string x : arr) {
        cout << x;
    }
}