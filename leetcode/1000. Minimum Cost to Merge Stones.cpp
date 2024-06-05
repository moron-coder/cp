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
    int dp[31][31];

    int help(vector<int> &ar,int st, int en, int k, vector<int> &prefs){
        if(st==en){
            return 0;
        }
        if(dp[st][en]!=-1) return dp[st][en];
        int totSum = prefs[en];
        if(st) totSum-=prefs[st-1];
        if((en-st)%(k-1)) totSum=0;
        int ans=INT_MAX;
        // ar[st]~ar[newEn] : left partition
        // ar[newEn+1]~ar[en] : right partition
        for(int newEn=st;newEn<en;newEn+=k-1){
            int smallSum = help(ar, st, newEn, k, prefs) + help(ar, newEn+1, en, k, prefs);
            ans=min(ans, smallSum);
        }
        int ret = (ans==INT_MAX?0:ans)+totSum;
        return dp[st][en] = ret;
    }

public:
    int mergeStones(vector<int>& ar, int k) {
        memset(dp,-1,sizeof(dp));
        int n=ar.size();
        if((n-1)%(k-1)) return -1;
        vector<int> prefs(n,ar[0]);
        for(int i=1;i<n;i++) prefs[i]=prefs[i-1]+ar[i];
        return help(ar,0,n-1,k,prefs);
    }
};