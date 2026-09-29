#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];
    // Find pivot
    int p = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) {
            p = i;
            break;
        }
    }
    // If no pivot, this is the last permutation
    if(p == -1) {
        reverse(arr.begin(), arr.end());
    }
    else {
        //Find element just greater than pivot
        for(int i = n - 1; i > p; i--) {
            if(arr[i] > arr[p]) {
                swap(arr[i], arr[p]);
                break;
            }
        }
        // Reverse suffix
        reverse(arr.begin() + p + 1, arr.end());
    }
    // Print result
    for(int x : arr) cout << x << " ";
}