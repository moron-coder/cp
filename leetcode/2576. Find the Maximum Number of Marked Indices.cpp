#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ok(vector<int> &ar,int mid){
        for(int i=mid-1,j=ar.size()-1;i>=0;i--,j--){
            if((ar[i]<<1)>ar[j]) return false;
        }
        return true;
    }

    int maxNumOfMarkedIndices(vector<int>& ar) {
        sort(ar.begin(),ar.end());
        int lo=0,n=ar.size(),hi=n/2,ans=0;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(ok(ar,mid)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans*2;
    }
};