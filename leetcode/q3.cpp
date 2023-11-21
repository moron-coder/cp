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
    int dp[1001][1001];

    int help(vector<int> &ar,int pos,int tg){
        if(pos>=ar.size()){
            return (tg==0)?0:-2;
        }
        if(dp[pos][tg]!=-1) return dp[pos][tg];
        int incAns = -2, nonIncAns = help(ar,pos+1,tg);
        if(tg>=ar[pos]){
            int small= help(ar,pos+1,tg-ar[pos]);
            if(small!=-2) incAns=1+small;
        }
        return dp[pos][tg] = max(incAns,nonIncAns);
    }

    int lengthOfLongestSubsequence(vector<int>& ar, int target) {
        memset(dp,-1,sizeof(dp));
        return max(-1,help(ar,0,target));
    }
};