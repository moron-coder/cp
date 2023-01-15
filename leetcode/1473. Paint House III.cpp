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
public:
    int dp[101][101][22];

    ll help(vector<int> &ar,int pos,int t,vector<vector<int>> &cost,ll prev){
        ll n=cost.size(),m=cost[0].size();
        if(t<0) return INT_MAX;
        if(pos>=n) return (t==0)?0:INT_MAX;
        if(dp[pos][t][prev+1]!=-1) return dp[pos][t][prev+1];
        if(ar[pos]) return dp[pos][t][prev+1]=help(ar,pos+1,t-((ar[pos]-1)!=prev),cost,(ar[pos]-1));
        ll ans=INT_MAX;
        for(ll j=0;j<m;j++){
            ans=min(ans,min((ll)INT_MAX,cost[pos][j]+help(ar,pos+1,t-(j!=prev),cost,j)));
        }
        return dp[pos][t][prev+1]=ans;
    }

    int minCost(vector<int>& ar, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        ll ans = help(ar,0,target,cost,-1);
        if(ans>=INT_MAX) return -1;
        return ans;   
    }
};