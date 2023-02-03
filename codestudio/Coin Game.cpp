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

int dp[1001][1001];

int help(vector<int> &ar,int st,int en){
    int n=ar.size();
    if(st>en) return 0;
    if(dp[st][en]!=-1) return dp[st][en];
    // ith
    int lf=ar[st]+min(help(ar,st+2,en),help(ar,st+1,en-1));
    int rt=ar[en]+min(help(ar,st+1,en-1),help(ar,st,en-2));
    return dp[st][en]=max(lf,rt);
}

int maxCoins(vector<int> ar, int n){
    memset(dp,-1,sizeof(dp));
    return help(ar,0,n-1);
}
