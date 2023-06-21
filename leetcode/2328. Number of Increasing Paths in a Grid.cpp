#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

class Solution {
    int di[4] = {0,0,1,-1};
    int dj[4] = {1,-1,0,0};
public:
    int rec(vector<vector<int>> &ar,int i,int j,int **dp){
        int n=ar.size(),m=ar[0].size();
        if(dp[i][j]) return dp[i][j];
        for(int dir=0;dir<4;dir++){
            int newI = i+di[dir],newJ = j+dj[dir];
            if(newI>=0 && newI<n && newJ>=0 && newJ<m && ar[newI][newJ]>ar[i][j]){
                dp[i][j]=(dp[i][j]+rec(ar,newI,newJ,dp))%mod;
            }
        }
        dp[i][j]=(dp[i][j]+1)%mod;
        return dp[i][j];
    }

    int countPaths(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size(),ans=0;
        int **dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[m]();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!dp[i][j]){
                    ans = (ans+rec(ar,i,j,dp))%mod;
                }else{
                    ans = (ans+dp[i][j])%mod;
                }
            }
        }
        // disp(dp,n,m);
        return ans;
    }
};