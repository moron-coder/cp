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
	int dp[301][11];

	int help(vector<int>& ar, int pos,int d){
        if(d==0) return (pos>=ar.size())?0:3000000;
		if(dp[pos][d]!=-1) return dp[pos][d];
	    int n=ar.size(),mx=ar[pos],ans=INT_MAX;
        for(int i=pos;i+d-1<n;i++){
	        mx=max(mx,ar[i]);
	        ans=min(ans,mx+help(ar,i+1,d-1));
        }
        return dp[pos][d] = ans;
    }


public:
    int minDifficulty(vector<int>& ar, int d) {
        if(d>ar.size()) return -1;
	    memset(dp,-1,sizeof(dp));
        return help(ar,0,d);
    }
};
