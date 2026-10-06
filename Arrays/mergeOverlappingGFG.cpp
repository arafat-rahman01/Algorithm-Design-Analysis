#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergOverlape(vector<vector<int>>&arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;

    for(auto i:arr){
        //no overlape
        if(ans.empty() || i[0] > ans.back()[1]) ans.push_back(i);

        //overlape-> merge
        else ans.back()[1]=max(ans.back()[1],i[1]);
    }
    return ans;
}

int main(){
    vector<vector<int>>arr={
        {1,3},
        {2,6},
        {8,10},
        {9,12}
    };
    vector<vector<int>>ans = mergOverlape(arr);

    for(auto x:ans){
        cout<<"[" <<x[0]<<", "<<x[1] <<"] ";
    }
}