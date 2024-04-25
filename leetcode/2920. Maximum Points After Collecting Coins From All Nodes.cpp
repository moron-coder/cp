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
    const static int LIMIT_HALVES_COUNT = 20;
    int dp[100001][LIMIT_HALVES_COUNT+1];
public:

    int getVal(int realVal, int halvesCt){
        for(int i=0;i<halvesCt;i++){
            realVal/=2;
        }
        return realVal;
    }

    int help(vector<vector<int>> &edges,int prev,int pos,int k,vector<int> &coins,int halvesCt){
        if(dp[pos][halvesCt]!=-1) return dp[pos][halvesCt];
        int ans1=getVal(coins[pos],halvesCt)-k;
        for(auto it:edges[pos]){
            if(prev!=it){
                ans1 += help(edges,pos,it,k,coins,halvesCt);
            }
        }
        int ans2=getVal(coins[pos],halvesCt)/2;
        for(auto it:edges[pos]){
            if(prev!=it){
                ans2 += help(edges,pos,it,k,coins,min(LIMIT_HALVES_COUNT,halvesCt+1));
            }
        }
        return dp[pos][halvesCt] = max(ans1,ans2);
    }

    int maximumPoints(vector<vector<int>>& ar, vector<int>& coins, int k) {
        int n=ar.size()+1;
        vector<vector<int>> edges(n);
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        memset(dp,-1,sizeof(dp));
        return help(edges,-1,0,k,coins,0);
    }
};