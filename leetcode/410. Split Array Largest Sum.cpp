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
    int dp[1001][51];

    int help(vector<int> &ar,int pos,int k){
        if(pos>=ar.size()) return k==0?0:INT_MAX;
        if(k==0) return INT_MAX;
        if(dp[pos][k]!=-1) return dp[pos][k];
        int sum=0,minSum=INT_MAX;
        for(int i=pos;i<ar.size();i++){
            sum+=ar[i];
            minSum = min(minSum,max(sum,help(ar,i+1,k-1)));
        }
        return dp[pos][k] = minSum;
    }

    int splitArray(vector<int>& ar, int k) {
        int n=ar.size();
        memset(dp,-1,sizeof(dp));
        return help(ar,0,k);
    }
};