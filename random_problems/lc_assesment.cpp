#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution {
public:
    int numSubmat(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size(),ans=0;
        vector<vector<pii>> dp(n,vector<pii>(m,{0,0}));
        // {left_one_count,ans[i][j]}
        dp[0][0]={ar[0][0],ar[0][0]};
        for(int i=1;i<n;i++){
            if(ar[i][0]) dp[i][0]={1,1+dp[i-1][0].second};
            ans+=dp[i][0].second;
        }
        for(int j=1;j<m;j++){
            if(ar[0][j]) dp[0][j]={1+dp[0][j-1].second,1+dp[0][j-1].second};
            ans+=dp[0][j].second;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(ar[i][j]){
                    int mn=1+dp[i][j-1].first;
                    dp[i][j].first=mn;
                    for(int k=i;k>=0 && ar[k][j];k--){
                        mn=min(mn,dp[k][j].first);
                        dp[i][j].second+=mn;
                    }
                    ans+=dp[i][j].second;
                }
            }
        }
        return ans;
    }
};