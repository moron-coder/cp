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
    int maxProfit(vector<int>& ar) {
        int n=ar.size(),ans=0;
        int dp[3][n+1];
        for(int i=0;i<=2;i++){
            dp[i][0]=0;
            dp[i][1]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=2;i++){
            int prev=-ar[0];
            for(int j=2;j<=n;j++){
                dp[i][j]=0;
                // dont do anything
                dp[i][j]=dp[i][j-1];
                // sell at j;
                dp[i][j]=max(dp[i][j],ar[j-1]+prev);
                prev=max(prev,dp[i-1][j-1]-ar[j-1]);
                ans=max(ans,dp[i][j]);
            }
        }
        //debug
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        //debug
        return ans;
    }
};