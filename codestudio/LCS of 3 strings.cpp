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

int dp[101][101][101];

int help(string &s1, string &s2, string &s3, int a, int b, int c){
    if(a>=s1.size() || b>=s2.size() || c>=s3.size()) return 0;
    if(dp[a][b][c]!=-1) return dp[a][b][c];
    if(s1[a]==s2[b] && s2[b]==s3[c]){
        return dp[a][b][c]=1+help(s1,s2,s3,a+1,b+1,c+1);
    }
    return dp[a][b][c]=max({help(s1,s2,s3,a+1,b,c),help(s1,s2,s3,a,b+1,c),help(s1,s2,s3,a,b,c+1)});
}

int LCS(string s1, string s2, string s3, int a, int b, int c){
    memset(dp,-1,sizeof(dp));
    return help(s1,s2,s3,0,0,0);
}