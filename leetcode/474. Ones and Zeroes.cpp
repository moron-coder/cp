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
    int dp[601][101][101];
public:
    int help(vector<string> &ar,int pos,int m,int n){
        int sz=ar.size();
        if(pos>=sz) return 0;
        if(dp[pos][m][n]!=-1) return dp[pos][m][n];
        int zct=0,oct=0;
        for(auto it:ar[pos]){
            if(it=='1') oct++;
            else zct++;
        }
        int ans = help(ar,pos+1,m,n);
        if(zct>m || oct>n){
            // cout<<pos<<" "<<m<<" "<<n<<" == "<<ans<<endl;
            return dp[pos][m][n]=ans;
        }
        ans = max(ans,1+help(ar,pos+1,m-zct,n-oct));
        // cout<<pos<<" "<<m<<" "<<n<<" = "<<ans<<endl;
        return dp[pos][m][n]=ans;
    }

    int findMaxForm(vector<string>& ar, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return help(ar,0,m,n);
    }
};