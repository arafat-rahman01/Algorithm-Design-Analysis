#include<bits/stdc++.h>
using namespace std;

int par(vector<int> &a,int low,int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;

    while(true){
        while(i<=high && a[i]<=pivot) i++;
        while(j>=low && a[j]>pivot) j--;
        if(i<j) swap(a[i],a[j]);
        else break;
    }
    swap(a[low],a[j]);
    return j;

}

void quickSort(vector<int> &a,int low,int high){
    if(low<high){
        int p=par(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);

    }
}
int main(){
    vector<int>a={12,34,2,3,67,4,7,5,11,14};
    quickSort(a,0,a.size()-1);
    for(int i:a){
        cout<<i<<" ";
    }
}