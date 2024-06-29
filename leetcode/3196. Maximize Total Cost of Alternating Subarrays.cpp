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
    long long dp[100001][2];

    long long help(vector<int> &ar, long long pos,bool isNeg){
        if(pos>=ar.size()){
            return 0;
        }
        if(dp[pos][isNeg]!=-1) return dp[pos][isNeg]; 
        long long curAns = isNeg?-ar[pos]:ar[pos];
        long long includeNxt = help(ar,pos+1,!isNeg);
        long long excludeNxt = help(ar,pos+1,false);
        return dp[pos][isNeg] = max(includeNxt, excludeNxt)+curAns;
    }
public:
    long long maximumTotalCost(vector<int>& ar) {
        long long n=ar.size();
        memset(dp,-1,sizeof(dp));
        return help(ar,0,false);
    }
};