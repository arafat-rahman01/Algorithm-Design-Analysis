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
    cin >> W;

    vector<pair<double,int>> vp;
    for(int i = 0; i < n; i++){
        vp.push_back({v[i]/w[i], i});
    }

    sort(vp.rbegin(), vp.rend());

    double profit = 0;

    for(auto p : vp){
        int i = p.second;

        if(W == 0) break;

        double take = min(W, w[i]);     
        profit += take * (v[i] / w[i]);
        W -= take;
    }
    cout << profit << endl;
}
