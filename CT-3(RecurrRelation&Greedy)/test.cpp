#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> v(n), w(n);
    for(int i = 0; i < n; i++){
        cin >> v[i] >> w[i];
    }

    double W;
    cin >> W;   // capacity

    // (value/weight, index)
    vector<pair<double,int>> vp;
    for(int i = 0; i < n; i++){
        vp.push_back({v[i]/w[i], i});
    }

    // highest ratio first
    sort(vp.rbegin(), vp.rend());

    double profit = 0;

    for(auto p : vp){
        int i = p.second;

        if(W == 0) break;

        double take = min(W, w[i]);      // যতটা নেওয়া যায়
        profit += take * (v[i] / w[i]);  // fraction value
        W -= take;
    }

    cout << profit << endl;
}
