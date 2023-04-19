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
    int inf=100000001;

    int minimumVisitedCells(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size();
        vector<vector<int>> cols(m,vector<int>());
        vector<vector<int>> dp(n,vector<int>(m,inf));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            vector<int> rows;
            for(int j=m-1;j>=0;j--){
                // I assume dp[i+x][j] and dp[i][j+x] have their corresponding answers saved
                // where x=ar[i][j]
                // I can't pop at first while taking min ans because.. if I pop for dp[i][j]>=dp[i][rows.back()]
                // then I may lose some better ans
                int rowMinAns=inf,colMinAns=inf;
                for(int k=rows.size()-1;k>=0 && rows[k]<=j+ar[i][j];k--){
                    rowMinAns=1+dp[i][rows[k]];
                }
                for(int k=cols[j].size()-1;k>=0 && cols[j][k]<=i+ar[i][j];k--){
                    colMinAns=1+dp[cols[j][k]][j];
                }
                dp[i][j]=min({colMinAns,rowMinAns,dp[i][j]});
                // now, dp[i][j] is min. Minimum value might be achieved via column and dp[i][j] can potentially
                // pop row and vice versa. So, repeat the above process
                while (rows.size() && rows.back()<=j+ar[i][j] && dp[i][j]<=dp[i][rows.back()]){
                    rows.pop_back();
                }
                while (cols[j].size() && cols[j].back()<=i+ar[i][j] && dp[i][j]<=dp[cols[j].back()][j]){
                    cols[j].pop_back();
                }
                cols[j].push_back(i);
                rows.push_back(j);                
            }
        }
        return (dp[0][0]==inf)?-1:dp[0][0];
    }
};