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
    int dp[301][301];

    int pow(int b,int p){
        if(p==0) return 1;
        int ans=1,small=pow(b,p/2);
        if(p&1){
            ans=b;
        }
        return (ans*small*small);
    }

    int help(int n,int x,int st){
        if(n==0) return 1;
        if(dp[n][st]!=-1) return dp[n][st];
        int ans=0;
        for(int i=st;pow(i,x)<=n;i++){
            ans=(help(n-pow(i,x),x,i+1)+ans)%mod;
        }
        return dp[n][st] = ans;
    }

    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return help(n,x,1);
    }
};