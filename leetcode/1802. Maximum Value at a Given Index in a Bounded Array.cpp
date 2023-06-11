#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution {
public:
    ll calcSum(int startNum, int endNum){
        ll curSum=0, preSum=0;
        if(startNum>1){
            preSum = calcSum(1,startNum-1);
        }
        ll tmp = (1LL*endNum*(endNum+1))/2-preSum;
        // cout<<startNum<<" to "<<endNum<<" returns "<<tmp<<endl;
        return tmp;
    }

    bool ok(int idx,int val,int maxSum,int n){
        // cout<<"for "<<val<<endl;
        ll preStart = max(0,val-idx), sufEnd = max(0,val-(n-1-idx));
        ll pSum = calcSum(preStart,val), sufSum = calcSum(sufEnd, val), tot = pSum+sufSum-val;
        // cout<<val<<" returns "<<tot<<endl;
        return tot<=maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        maxSum-=n;
        ll lo=0,hi=maxSum,ans=1;
        while (lo<=hi){
            ll mid = lo+(hi-lo)/2;
            if(ok(index,mid,maxSum,n)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans+1;
    }
};