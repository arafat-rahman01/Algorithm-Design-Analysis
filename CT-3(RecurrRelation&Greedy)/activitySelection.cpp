#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> start(n), finish(n);
    for(int i = 0; i < n; i++)
        cin >> start[i] >> finish[i];

    // pair: (finish, start)
    vector<pair<int,int>> activities;
    for(int i = 0; i < n; i++)
        activities.push_back({finish[i], start[i]});

    // sort by finish time
    sort(activities.begin(), activities.end());

    vector<int> selected;
    int lastFinish = 0;

    for(int i = 0; i < n; i++){
        if(activities[i].second >= lastFinish){
            selected.push_back(i);          // store index (optional)
            lastFinish = activities[i].first;
        }
    }

    cout << "Maximum number of activities = " << selected.size() << endl;
    cout << "Activities selected (sorted by finish time index) = ";
    for(int idx : selected)
        cout << idx << " ";
    cout << endl;

    return 0;
}
