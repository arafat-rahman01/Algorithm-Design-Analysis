#include<bits/stdc++.h>
using namespace std;

// Partition function (Hoare)
int partition(vector<int>& a, int low, int high){
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(true){
        while(i <= high && a[i] <= pivot) i++;
        while(j >= low && a[j] > pivot) j--;
        if(i < j) swap(a[i], a[j]);
        else break;
    }
    swap(a[low], a[j]);
    return j;
}

// Iterative Quick Sort
void quickSortIter(vector<int>& a){
    stack<pair<int,int>> s;
    s.push({0, (int)a.size()-1});

    while(!s.empty()){
        int low = s.top().first;
        int high = s.top().second;
        s.pop();

        if(low < high){
            int p = partition(a, low, high);
            s.push({low, p-1});   // left subarray
            s.push({p+1, high});  // right subarray
        }
    }
}

int main(){
    vector<int> a = {12,34,2,3,67,4,7,5,11,14};

    quickSortIter(a);

    for(int x : a) cout << x << " ";
}
