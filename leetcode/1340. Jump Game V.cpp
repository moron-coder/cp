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
    int dp[1001];

    int help(vector<int> &ar,int pos,int d){
        int n=ar.size(),ans=1;
        if(dp[pos]!=-1) return dp[pos];
        for(int i=pos+1;i<min(n-1,pos+d) && ar[pos]>ar[i];i++){
            int sm=help(ar,i,d);
            ans=max(ans,sm+1);
        }
        for(int i=pos-1;i<max(0,pos-d) && ar[pos]>ar[i];i--){
            int sm=help(ar,i,d);
            ans=max(ans,sm+1);
        }
        return dp[pos]=ans;
    }

    int maxJumps(vector<int>& ar, int d) {
        memset(dp,-1,sizeof(dp));
        int ans=1,n=ar.size();
        for(int i=0;i<n;i++){
            ans=max(ans,help(ar,i,d));
        }
        return ans;
    }
};