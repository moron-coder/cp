#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

class Solution {
    const static ll MAX_ANS = 500000001;
public:
    int dp[501][2001];

    ll rec(vector<int> &costs,vector<int> &times,int pos,ll freeWallsCt,ll allowedFree){
        // min cost to paint walls[pos]~walls[n-1]
        ll n=costs.size();
        if(dp[pos][min(n,allowedFree)-freeWallsCt+1001]!=-1) return dp[pos][min(n,allowedFree)-freeWallsCt+1001];
        if(pos>=n){
            if(allowedFree>=freeWallsCt) return 0;
            return MAX_ANS;
        }
        ll paintFree = MAX_ANS, paintNotFree = MAX_ANS;
        paintFree = min(MAX_ANS, rec(costs,times,pos+1,freeWallsCt+1,allowedFree));
        paintNotFree = min(MAX_ANS, costs[pos]+rec(costs,times,pos+1,freeWallsCt,allowedFree+times[pos]));
        return dp[pos][min(n,allowedFree)-freeWallsCt+1001] = min(paintFree,paintNotFree);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        return rec(cost,time,0,0,0);
    }
};