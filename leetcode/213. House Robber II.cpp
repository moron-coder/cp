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
    int dp[101][101];
    int help(vector<int> &ar,int st,int en){
        if(st>en) return 0;
        if(dp[st][en]!=-1) return dp[st][en];
        int ans=0;
        for(int i=st;i<=en;i++){
            ans=max(ans, help(ar,i+2,en)+help(ar,st,i-2)+ar[i]);
        }
        return dp[st][en]=ans;
    }
public:
    int rob(vector<int>& ar) {
        memset(dp,-1,sizeof(dp));
        int n=ar.size();
        return max({ar[0],help(ar,0,n-2),help(ar,1,n-1)});
    }
};