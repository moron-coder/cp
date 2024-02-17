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

int help(vector<int> &ar,int pos,int k,int** dp){
    if(pos<0){
        return k==0;
    }
    if(dp[pos][k]!=-1) return dp[pos][k];
    int ans1 = help(ar,pos-1,k,dp),ans2=0;
    if(ar[pos]<=k){
        ans2=help(ar,pos-1,k-ar[pos],dp);
    }
    return dp[pos][k]=(ans1+ans2)%mod;
}

int findWays(vector<int>& ar, int k){
    int **dp=new int*[ar.size()];
    for(int i=0;i<ar.size();i++){
        dp[i]=new int[k]();
        for(int j=0;j<k;j++) dp[i][j]=-1;
    }
    return help(ar,ar.size()-1,k,dp);
}
