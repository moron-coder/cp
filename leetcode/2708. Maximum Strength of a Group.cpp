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
    const static int MAX_N=13;

    pll dp[MAX_N][(1<<MAX_N)+1];

    pll rec(int pos,vector<int> &ar,int config){
        // returns {min,max} possible product
        int n=ar.size();
        if(dp[pos][config].first!=-1) return dp[pos][config];
        pll defSkipped = {ar[pos],ar[pos]}, defTaken = {1,1};
        ll minAns=ar[pos],maxAns=ar[pos];
        pll skipped = (pos+1>=n)?defSkipped:rec(pos+1,ar,config);
        pll taken = (pos+1>=n)?defTaken:rec(pos+1,ar,config|(1<<pos));
        minAns = min({minAns, taken.first*ar[pos], taken.second*ar[pos],skipped.first,skipped.second});
        maxAns = max({maxAns, taken.first*ar[pos], taken.second*ar[pos],skipped.first,skipped.second});
        return dp[pos][config]={minAns,maxAns};
    }

    long long maxStrength(vector<int>& ar){
        memset(dp,-1,sizeof(dp));
        return rec(0,ar,0).second;
    }
};