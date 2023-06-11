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
    bool isIntersecting(vector<int> &b1,vector<int> &b2){
        ll r1=b1[2],r2=b2[2],x1=b1[0],y1=b1[1],x2=b2[0],y2=b2[1];
        ll d2 = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        return (r1*r1>=d2); 
    }

    int dfs(vector<vector<int>> &ar,int pos,vector<int> &dp,vector<bool> &vis){
        if(dp[pos]){
            return dp[pos];
        }
        int ans=1;
        for(int i=0;i<ar.size();i++){
            if(!vis[i] && isIntersecting(ar[pos],ar[i])){
                vis[i]=true;
                ans+=dfs(ar,i,dp,vis);
            }
        }
        return dp[pos]=ans;
    }

    int maximumDetonation(vector<vector<int>>& ar) {
        int n=ar.size(),ans=0;
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            vector<int> dp(n,0);
            vis[i]=true;
            ans=max(ans,dfs(ar,i,dp,vis));
        }
        return ans;
    }
};