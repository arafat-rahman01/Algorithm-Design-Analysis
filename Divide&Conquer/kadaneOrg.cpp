#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int curr_sum=a[0];
    int max_sum=a[0];
    for(int i=0;i<n;i++){
        curr_sum=max(a[i],a[i]+curr_sum);
        max_sum=max(curr_sum,max_sum);
    }
    cout<<max_sum<<endl;
}