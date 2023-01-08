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
    ll dp[100001];

    ll help(int pos,vector<int> &ar,vector<int> &costs,vector<int> &nextGrEq,vector<int> &nextSm){
        int n=ar.size();
        if(pos==n-1) return 0;
        ll ans=LONG_MAX;
        if(nextGrEq[pos]!=-1){
            ll small=help(nextGrEq[pos],ar,costs,nextGrEq,nextSm);
            if(small!=-2) ans=min(ans,costs[nextGrEq[pos]]+small);
        }
        if(nextSm[pos]!=-1){
            ll small=help(nextSm[pos],ar,costs,nextGrEq,nextSm);
            if(small!=-2) ans=min(ans,costs[nextSm[pos]]+small);
        }
        if(ans==LONG_MAX) return dp[pos]=-2;
        return dp[pos]=ans;
    }

    long long minCost(vector<int>& ar, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        int n=ar.size();
        vector<int> nextGrEq(n,-1),nextSm(n,-1);
        //  nextGrEq will be strictly decreasing mono stack
        //  On pop operation, nextGrEq will save info even if an equal element is found
        //  nextSm will be strictly increasing mono stack
        //  On pop operation, nextSm will not save info if an equal element is found
        vector<int> stk1,stk2;
        for(int i=0;i<n;i++){
            while (stk1.size() && ar[stk1.back()]<=ar[i]){
                nextGrEq[stk1.back()]=i;                                //  saving greater than or equal element
                stk1.pop_back();
            }
            stk1.push_back(i);
        }
        for(int i=0;i<n;i++){
            while (stk2.size() && ar[stk2.back()]>ar[i]){
                nextSm[stk2.back()]=i;                                  //  saving only strictly less element
                stk2.pop_back();
            }
            stk2.push_back(i);
        }
        return help(0,ar,costs,nextGrEq,nextSm);
    }
};