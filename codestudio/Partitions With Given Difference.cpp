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

int dp[51][2501];

int help(vector<int> &ar,int pos,int sum){
    int n=ar.size();
    if(pos>=n){
        return sum==0;
    }
    if(sum<0) return 0;
    if(dp[pos][sum]!=-1) return dp[pos][sum]%mod;
    int nInc = help(ar,pos+1,sum)%mod,inc=0;
    if(ar[pos]<=sum){
        inc=help(ar,pos+1,sum-ar[pos])%mod;
    }
    return dp[pos][sum]=(inc+nInc)%mod;
}


int countPartitions(int n, int d, vector<int> &ar) {

    memset(dp,-1,sizeof(dp));
    int sum=0;
    for(auto it:ar) sum+=it;
    // one of the numbers is x, other is x+d
    if((sum-d)<0 || (sum-d)&1) return 0;
    int x=(sum-d)/2;
    // find number of ways to get x from ar;
    return help(ar,0,x)%mod;
}
