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
    int dp[30001][2];

    int maxPointsOnSelling(int pos,vector<int> &ar,bool canBuy){
        int n=ar.size();
        if(pos>=n) return 0;
        if(dp[pos][canBuy]!=-1) return dp[pos][canBuy];
        int ignoreAns = maxPointsOnSelling(pos+1,ar,canBuy);
        int buyIgnoreAns = (canBuy)? max(0,maxPointsOnSelling(pos+1,ar,false)-ar[pos]):0;
        int sellAns = (!canBuy)?ar[pos]+maxPointsOnSelling(pos+1,ar,true):0;
        return dp[pos][canBuy] = max({ignoreAns,buyIgnoreAns,sellAns});
    }

    int maxProfit(vector<int>& ar) {
        int n=ar.size();
        memset(dp,-1,sizeof(dp));
        return maxPointsOnSelling(0,ar,true);
    }
};