#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;  // number of jobs
    vector<int> id(n), deadline(n), profit(n);

    for(int i=0; i<n; i++)
        cin >> id[i] >> deadline[i] >> profit[i];

    // sort jobs by profit (descending)
    vector<pair<int,pair<int,int>>> jobs;
    for(int i=0;i<n;i++) jobs.push_back({profit[i], {deadline[i], id[i]}});
    sort(jobs.rbegin(), jobs.rend());

    int maxDeadline = 0;
    for(auto &j: jobs) maxDeadline = max(maxDeadline, j.second.first);

    vector<int> slot(maxDeadline+1, -1);
    int total = 0;

    for(auto &j : jobs){
        for(int d = j.second.first; d > 0; d--){
            if(slot[d] == -1){
                slot[d] = j.second.second; // job id
                total += j.first; // profit
                break;
            }
        }
    }

    cout << "Jobs done: ";
    for(int i=1; i<=maxDeadline; i++)
        if(slot[i] != -1) cout << slot[i] << " ";

    cout << "\nTotal profit: " << total << endl;
}
