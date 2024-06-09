#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[4000001];

    int help(vector<int> &ar,int pos, int val){
        int n=ar.size();
        if(pos>=n){
            return val;
        }
        if(dp[val]!=-1) return dp[val];
        int nextPos = upper_bound(ar.begin(),ar.end(),val+ar[pos])-ar.begin();
        int takeAns = help(ar,nextPos,val+ar[pos]), notTakeAns = help(ar,pos+1,val);
        return dp[val] = max(takeAns, notTakeAns);
    }
public:
    int maxTotalReward(vector<int>& ar) {
        memset(dp,-1,sizeof(dp));
        sort(ar.begin(),ar.end());
        return help(ar,0,0);
    }
};