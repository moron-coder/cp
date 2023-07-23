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
    int dp[100001][2];

    int help(vector<int> &ar1,vector<int> &ar2,int pos,int lastFrom){
        //  lastFrom = 0 : last element was taken from ar1
        //  lastFrom = 1 : last element was taken from ar2
        int n=ar1.size();
        if(pos>=n) return 1;
        if(dp[pos][lastFrom]!=-1) return dp[pos][lastFrom];
        int ans=1,getAr1=1,getAr2=1;
        int lastElement = (lastFrom)?ar2[pos-1]:ar1[pos-1];
        if(ar1[pos]>=lastElement){
            getAr1 = 1+help(ar1,ar2,pos+1,0);
        }else{
            getAr1 = 1;
        }
        if(ar2[pos]>=lastElement){
            getAr2 = 1+help(ar1,ar2,pos+1,1);
        }else{
            getAr2 = 1;
        }
        return dp[pos][lastFrom] = max(getAr1,getAr2);
    }

    int maxNonDecreasingLength(vector<int>& ar1, vector<int>& ar2) {
        if(ar1.size()==1) return 1;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<ar1.size();i++){
            help(ar1,ar2,i,0);
            help(ar1,ar2,i,1);
        }
        int ans=0;
        for(int i=0;i<ar1.size();i++){
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};