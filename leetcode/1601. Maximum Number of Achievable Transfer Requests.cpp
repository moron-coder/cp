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
    int dp[(1<<16)];

    int help(vector<vector<int>> &ar,int pos,vector<int> &netChange,int state){
        int n=ar.size();
        if(pos>=n){
            for(auto it:netChange) if(it!=0) return -2;
            return 0;
        }
        if(dp[state]!=-1) return dp[state];
        int acceptRequest = -2, rejectRequest = help(ar,pos+1,netChange,state);
        netChange[ar[pos][0]]--;
        netChange[ar[pos][1]]++;
        int acceptRequestSmall = help(ar,pos+1,netChange,state^(1<<pos));
        netChange[ar[pos][0]]++;
        netChange[ar[pos][1]]--;
        if(acceptRequestSmall!=-2){
            acceptRequest = 1+acceptRequestSmall;
        }
        return dp[state]=max(acceptRequest,rejectRequest);
    }

    int maximumRequests(int n, vector<vector<int>>& ar) {
        vector<int> netChange(n,0);
        memset(dp,-1,sizeof(dp));
        return max(0,help(ar,0,netChange,0));
    }
};