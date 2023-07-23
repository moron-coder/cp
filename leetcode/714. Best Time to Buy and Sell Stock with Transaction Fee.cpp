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
    int dp[50001][2];

    int help(vector<int> &ar,int pos,bool alreadyBought,int k){
        int n=ar.size();
        if(pos== n-1){
            if(alreadyBought) return ar[pos]-k;
            return 0;
        }
        if(dp[pos][alreadyBought]!=-1) return dp[pos][alreadyBought];
        if(alreadyBought){
            return dp[pos][alreadyBought] = max(ar[pos]-k+help(ar,pos+1,false,k),help(ar,pos+1,true,k));
        }
        return dp[pos][alreadyBought] = max(help(ar,pos+1,false,k),-ar[pos]+help(ar,pos+1,true,k));
    }

    int maxProfit(vector<int>& ar, int k) {
        memset(dp,-1,sizeof(dp));
        return help(ar,0,false,k);
    }
};