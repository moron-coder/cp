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
    const static int MIN_ANS = -1000000000;
public:
    long long dp[100001][3];

    long long help(vector<int> &ar,int x,int pos,int prevState){
        // prevState : 
        //  -1 : no number selected prior
        //  0  : even number selected prior
        //  1  : odd number selected prior
        int n=ar.size();
        if(pos>=n) return 0;
        if(dp[pos][prevState+1]!=-1) return dp[pos][prevState+1];
        long long maxAns = pos?help(ar,x,pos+1,prevState):MIN_ANS;
        if(prevState!=-1){
            if(1&(ar[pos]^prevState)){
                // different parity
                maxAns=max(maxAns,ar[pos]-x+help(ar,x,pos+1,1-prevState));
            }else{
                // same parity
                maxAns=max(maxAns,ar[pos]+help(ar,x,pos+1,prevState));
            }
        }else{
            maxAns=max(maxAns,ar[pos]+help(ar,x,pos+1,1&ar[pos]));
        }
        return dp[pos][prevState+1] = maxAns;
    }

    long long maxScore(vector<int>& ar, int x) {
        memset(dp,-1,sizeof(dp));
        return help(ar,x,0,-1);
    }
};