#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int

class Solution {
    int dp[101][101][21];
public:
    int help(vector<int> &houses,vector<vector<int>> &cost,int target,int pos,int prev){
        int n=houses.size(),ans=1e7;
        if(pos>=n) return (target==0)?0:1e7;
        if(target<0) return 1e7;                                                    //  neighbors exhausted
        if(prev!=-1 && dp[pos][target][prev]!=-1) return dp[pos][target][prev];
        if(houses[pos]){
            if(houses[pos]==prev) return help(houses,cost,target,pos+1,houses[pos]);    // no extra cost, target is same
            return help(houses,cost,target-1,pos+1,houses[pos]);                        // no extra cost, target--
        }
        //  try all the colors on houses[pos]
        for(int clr=0;clr<cost[pos].size();clr++){
            if(clr+1==prev) ans=min(ans,cost[pos][clr]+help(houses,cost,target,pos+1,clr+1));
            else ans=min(ans,cost[pos][clr]+help(houses,cost,target-1,pos+1,clr+1));
        }
        if(prev!=-1) dp[pos][target][prev]=ans;
        return ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // for any position 'pos' we'll return what is the min cost of coloring ar[pos]~ar[n-1] such that exactly 'target' neighbors are generated
        memset(dp,-1,sizeof(dp));
        int ans = help(houses,cost,target,0,-1);
        return ans==1e7?-1:ans;
    }
};