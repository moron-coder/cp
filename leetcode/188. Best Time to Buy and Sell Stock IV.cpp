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
    int maxProfit(int k, vector<int>& ar) {
        int n=ar.size();
        int dp[n+1][k+1];
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=k;j++) dp[0][j]=0;
        for(int j=1;j<=k;j++){
            int preMax=-10000000;
            for(int i=1;i<=n;i++){
                // dp[i][j] : max profit uptill day 'i' if we have max 'j' transactions
                dp[i][j]=max(dp[i-1][j],ar[i-1]+preMax);
                preMax=max(preMax,-ar[i-1]+dp[i-1][j-1]);
            }
        }
        return dp[n][k];
    }
};