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
    int di[2]={1,0};
    int dj[2]={0,1};

    int help(vector<vector<int>>& ar, int k,int i,int j,int sum,int ***dp){
        int n=ar.size(),m=ar[0].size(),ans=0;
        if(i==n-1 && j==m-1){
            return (sum%k)==0;
        }
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        for(int dir=0;dir<2;dir++){
            int newI=i+di[dir],newJ=j+dj[dir];
            if(newI>=0 && newI<n && newJ>=0 && newJ<m){
                ans=(ans+help(ar,k,newI,newJ,(sum+ar[newI][newJ])%k,dp))%mod;
            }
        }
        return dp[i][j][sum]=ans;
    }

    int numberOfPaths(vector<vector<int>>& ar, int k) {
        int n=ar.size(),m=ar[0].size();
        // int **dp=new int*[n];
        // for(int i=0;i<n;i++) dp[i]=new int[m]();
        int ***dp=new int**[n];
        for(int i=0;i<n;i++){
            dp[i]=new int*[m];
            for(int j=0;j<m;j++) dp[i][j]=new int[k]();
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int it=0;it<k;it++) dp[i][j][it]=-1;
        return help(ar,k,0,0,ar[0][0]%k,dp);
    }
};