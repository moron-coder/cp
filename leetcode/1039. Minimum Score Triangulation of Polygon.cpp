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
    int dp[1001][1001];

    int minScoreTriangulation(vector<int>& ar,int lf,int rt) {
        if(lf+2>rt){
            return 0;
        }
        if(dp[lf][rt]!=-1) return dp[lf][rt];
        int ans=INT_MAX;
        for(int i=lf+1;i<rt;i++){
            ans = min(ans, minScoreTriangulation(ar,lf,i) + ar[lf]*ar[i]*ar[rt] + minScoreTriangulation(ar,i,rt));
        }
        return dp[lf][rt] = ans;
    }

public:
    int minScoreTriangulation(vector<int>& ar) {
        memset(dp,-1,sizeof(dp));
        return minScoreTriangulation(ar,0,ar.size()-1);
    }
};