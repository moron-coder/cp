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
    pii dp[41][41];
public:
    pii help(vector<int> &ar,int st,int en){
        if(st==en){
            return {0,ar[st]};          //  {sum, max_num}
        }
        if(dp[st][en].first!=-1) return dp[st][en];
        int ans=INT_MAX,mx=-1;
        for(int i=st+1;i<=en;i++){
            //  ar[st]~ar[i-1] and ar[i]~ar[en]
            pii lf = help(ar,st,i-1), rt = help(ar,i,en);
            ans=min(ans,lf.first+rt.first+lf.second*rt.second);
            mx=max({mx,lf.second,rt.second});
        }
        return dp[st][en] = {ans, mx};
    }

    int mctFromLeafValues(vector<int>& ar) {
        for(int i=0;i<=40;i++){
            for(int j=0;j<=40;j++){
                dp[i][j]={-1,-1};
            }
        }
        int n=ar.size();
        return help(ar,0,n-1).first;
    }
};