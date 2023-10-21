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
    const static int md = 12345;
public:
    void solve(vector<vector<int>> &ar,vector<vector<int>> &ans){
        long long n=ar.size(),m=ar[0].size(),runningProd = 1;
        vector<vector<int>> pre(n,vector<int>(m,-1)),suf(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j] = runningProd;
                runningProd = (1LL*runningProd*ar[i][j])%md;
            }
        }
        runningProd = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suf[i][j] = runningProd;
                runningProd = (1LL*runningProd*ar[i][j])%md;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = (pre[i][j]*suf[i][j])%md;
            }
        }
    }

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        solve(ar,ans);
        return ans;
    }
};