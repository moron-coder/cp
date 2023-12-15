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

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

class Solution {
public:
    int help(vector<vector<int>> &ar,int curI,int curJ, int **dp){
        int n=ar.size(),m=ar[0].size(),ans=1;
        if(dp[curI][curJ]!=-1) return dp[curI][curJ];
        for(int dir=0;dir<4;dir++){
            int newI = curI+di[dir], newJ = curJ+dj[dir];
            if(newI>=0 && newI<n && newJ>=0 && newJ<m && ar[newI][newJ]>ar[curI][curJ]){
                ans = max(ans,1+help(ar,newI,newJ,dp));
            }
        }
        return dp[curI][curJ]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size(),ans=0;
        int **dp=new int*[n]();
        for(int i=0;i<n;i++){
            dp[i]=new int[m]();
            for(int j=0;j<m;j++) dp[i][j]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,help(ar,i,j,dp));
            }
        }
        return ans;
    }
};