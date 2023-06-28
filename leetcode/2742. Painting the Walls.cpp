#include <bits/stdc++.h>
using namespace std;

class Solution {
    int MAX_ANS = 500000001;
    int dp[501][501];
public:
    int rec(vector<int> &cost,int pos,vector<int> &time,int timeEarned){
        int n=cost.size();
        if(pos>=n){
            if(timeEarned==n) return 0;
            return MAX_ANS;
        }
        if(dp[pos][min(n,timeEarned)]!=-1) return dp[pos][min(n,timeEarned)];
        int take = MAX_ANS, notTake = MAX_ANS;
        take = rec(cost,pos+1,time,min(n,timeEarned+time[pos]+1))+cost[pos];
        notTake = rec(cost,pos+1,time,timeEarned);
        take = min(MAX_ANS,take);
        notTake = min(MAX_ANS,notTake);
        return dp[pos][min(n,timeEarned)] = min(take,notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        // we have to earn time. Total time>=n
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        return rec(cost,0,time,0);
    }
};