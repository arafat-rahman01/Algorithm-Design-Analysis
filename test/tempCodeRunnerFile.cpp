void ms1(vector<int>&arr,int st,int end){
    if(st<end){
        int mid=(st+end)/2;
        ms1(arr,st,mid);
        ms1(arr,mid+1,end);
        me(arr,st,mid,end);
    }
}

