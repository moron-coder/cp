#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& ar, int p) {
        int n=ar.size(),ans=0,hi=1000000000,lo=0;
        sort(ar.begin(),ar.end());
        while (lo<=hi){
            int mid=lo+(hi-lo)/2,cur=0;
            for(int i=1;i<n;){
                if(ar[i]-ar[i-1]<=mid){
                    i+=2,cur++;
                }else{
                    i++;
                }
            }
            if(cur>=p){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;
    }
};