#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);
    for(int i=0; i<n; i++){
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // sort jobs by profit descending
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for(auto job : jobs) maxDeadline = max(maxDeadline, job.deadline);

    vector<int> slot(maxDeadline + 1, -1); // slot[i] = job id or -1

    int totalProfit = 0;
    vector<int> selectedJobs;

    for(auto job : jobs){
        for(int j = job.deadline; j > 0; j--){
            if(slot[j] == -1){
                slot[j] = job.id;
                totalProfit += job.profit;
                selectedJobs.push_back(job.id);
                break;
            }
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
    cout << "Jobs selected: ";
    for(int id : selectedJobs) cout << id << " ";
    cout << endl;

    return 0;
}
