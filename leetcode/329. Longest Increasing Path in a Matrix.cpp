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

// 9:37

int di[]={0,0,-1,1};
int dj[]={1,-1,0,0};

class Solution {
public:
    int dp[201][201];

    int help(vector<vector<int>> &ar,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int n=ar.size(),m=ar[0].size(),curAns=1;
        for(int dir=0;dir<4;dir++){
            int newI=i+di[dir],newJ=j+dj[dir];
            if(newI>=0 && newI<n && newJ>=0 && newJ<m && ar[newI][newJ]>ar[i][j]){
                curAns=max(curAns,1+help(ar,newI,newJ));
            }
        }
        return dp[i][j]=curAns;
    }

    int longestIncreasingPath(vector<vector<int>>& ar) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<ar.size();i++){
            for(int j=0;j<ar[0].size();j++){
                ans=max(ans,help(ar,i,j));
            }
        }
        return ans;
    }
};