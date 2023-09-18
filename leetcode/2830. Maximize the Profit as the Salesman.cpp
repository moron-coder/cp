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
    int n;
    int dp[100001];
    public:

    int help(vector<vector<int>> &ar,int pos){
        if(pos>=n) return 0;
        if(dp[pos]!=-1) return dp[pos];
        int ans=help(ar,pos+1);
        int hi=n-1,lo=pos+1,nxtPos=n;
        while (lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(ar[mid][0]>ar[pos][1]){
                nxtPos=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        ans = max(ans,help(ar,nxtPos)+ar[pos][2]);
        return dp[pos]=ans;
    }

    int maximizeTheProfit(int n1, vector<vector<int>>& ar) {
        sort(ar.begin(),ar.end());
        n=ar.size();
        memset(dp,-1,sizeof(dp));
        return help(ar,0);
    }
};