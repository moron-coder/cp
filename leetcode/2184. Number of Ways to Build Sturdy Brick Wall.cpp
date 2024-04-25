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
#define ll long long int
#define mod 1000000007

class Solution {
public:
    int dp[101][1025];

    int help(int n,int m,int i,int j,int prev,int cur,vector<int> &ar){
        if(dp[i][prev]!=-1 && j==0){
            return dp[i][prev];
        }
        if(i>=n){
            return 1;
        }
        int ans=0;
        for(int k=0;k<ar.size();k++){
            int newBit = cur|(1<<(j+ar[k]-1));
            if(j+ar[k]-1>=m){
                continue;
            } else if(j+ar[k]-1==m-1){
                ans = (ans+help(n,m,i+1,0,newBit,0,ar))%mod;
            } else if(prev&(1<<(j+ar[k]-1))){
                continue;
            } else{
                ans = (ans+help(n,m,i,j+ar[k],prev,newBit,ar))%mod;
            }
        }
        return j==0?dp[i][prev] = ans:ans;
    }

    int buildWall(int height, int width, vector<int>& bricks) {
        memset(dp,-1,sizeof(dp));
        return help(height,width,0,0,0,0,bricks);
    }
};