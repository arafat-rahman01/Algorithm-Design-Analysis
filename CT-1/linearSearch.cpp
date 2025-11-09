#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[]={1,3,5,6,3};
    int val=5,c=0;
    for(int i=0;i<5;i++){
        if(arr[i]==val){
            c++;
            cout<<"FOUND";
            break;
        }
    }
    if(c==0) cout<<"NOT FOUND";
}
