#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> act(n);

    for(int i=0; i<n; i++){
        cin >> act[i].first >> act[i].second;
        // first = start, second = finish
    }

    // sort by finishing time
    sort(act.begin(), act.end(), 
        [](auto &a, auto &b){
            return a.second < b.second;
        });

    int count = 1;           // প্রথম activity নেব
    int lastFinish = act[0].second;

    for(int i=1; i<n; i++){
        if(act[i].first >= lastFinish){
            count++;
            lastFinish = act[i].second;
        }
    }

    cout << count << endl;

    return 0;
}
