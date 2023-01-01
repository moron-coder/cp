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

    int checkRecord(int n) {
        int dp[n+1][2][3];      //  dp[cur][total leaves uptill cur][total cts late uptill cur]
        memset(dp,0,sizeof(dp));
        for(int i=n;i>=0;i--){
            for(int j=1;j>=0;j--){
                for(int k=2;k>=0;k--){
                    if(i==n){
                        dp[i][j][k]=1;
                        continue;
                    }
                    dp[i][j][k]=(dp[i][j][k]+dp[i+1][j][0])%mod;
                    if(j+1<2) dp[i][j][k]=(dp[i][j][k]+dp[i+1][j+1][0])%mod;
                    if(k+1<3) dp[i][j][k]=(dp[i][j][k]+dp[i+1][j][k+1])%mod;
                }
            }
        }
        return dp[0][0][0];
    }
};

/*
class Solution {
public:
    int dp[100001][2][3];
    int N;

    int help(int pos,int abs,int lates){
        if(abs>=2 || lates>=3) return 0;
        if(pos>=N) return 1;
        if(dp[pos][abs][lates]!=-1) return dp[pos][abs][lates];
        int ans=help(pos+1,abs,0);          // go on time today
        ans=(ans+help(pos+1,abs+1,0))%mod;  //  absent today
        ans=(ans+help(pos+1,abs,lates+1))%mod;  //  late today
        return dp[pos][abs][lates]=ans;
    }

    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        N=n;
        return help(0,0,0);
    }
};
*/