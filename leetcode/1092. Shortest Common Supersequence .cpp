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
    int dp[1001][1001],lenDp[1001][1001];

    char *ss1,*ss2;
    int n,m;

    int help(int x, int y){
        if(x>=n || y>=m){
            return max(n-x,m-y);
        }
        if(lenDp[x][y]!=-1) return lenDp[x][y];
        int takeBothAns=INT_MAX;
        if(ss1[x]==ss2[y]){
            takeBothAns=min(takeBothAns,1+help(x+1,y+1));
        }
        int small1 = help(x+1,y)+1, small2 = help(x,y+1)+1, globalMin = min({takeBothAns,small1,small2});
        if(small1==globalMin){
            dp[x][y]=0;
        }else if(small2==globalMin) {
            dp[x][y]=1;
        }else{
            dp[x][y]=2;
        }
        return lenDp[x][y] = globalMin;
    }

    string shortestCommonSupersequence(string s1, string s2) {
        ss1 = &s1[0];
        ss2 = &s2[0];
        memset(dp,-1,sizeof(dp));
        memset(lenDp,-1,sizeof(lenDp));
        n=s1.size(),m=s2.size();
        int minLen = help(0,0);
        int i=0,j=0;
        string ans;
        while (i<n && j<m){
            if(dp[i][j]==0){
                ans.push_back(s1[i++]);
            }else if(dp[i][j]==1){
                ans.push_back(s2[j++]);
            }else if(dp[i][j]==2){
                ans.push_back(s1[i++]);
                j++;
            }else{
                cout<<"not possible\n";
                i++,j++;
            }
        }
        while (i<n){
            ans.push_back(s1[i++]);
        }
        while (j<m){
            ans.push_back(s2[j++]);
        }
        return ans;
    }
};