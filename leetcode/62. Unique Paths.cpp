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

    int help(int m,int n){
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = m?help(m-1,0):0 + n?help(m,n-1):0;
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return help(m-1,n-1);
    }
};