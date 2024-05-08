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
    int longestArithSeqLength(vector<int>& ar) {
        int n=ar.size(),ans=0;
        vector<vector<int>> dp(1001,vector<int>(1001,1));
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                dp[i][ar[i]-ar[j]+500] = max(dp[i][ar[i]-ar[j]+500], 1+dp[j][ar[i]-ar[j]+500]);
                ans=max(dp[i][ar[i]-ar[j]+500], ans);
            }
        }
        return ans;
    }
};