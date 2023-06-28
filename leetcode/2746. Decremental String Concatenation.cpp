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
    int dp[1001][26][26];

    int rec(vector<string> &ar,int pos,int prevLastChar,int prevFirstChar){
        int n=ar.size();
        if(pos>=n) return 0;
        if(dp[pos][prevFirstChar][prevLastChar]!=-1) return dp[pos][prevFirstChar][prevLastChar];
        int curLen = ar[pos].size(),conc=INT_MAX,swapConc=INT_MAX;
        if((ar[pos][0]-'a')==prevLastChar){
            conc = curLen-1+rec(ar,pos+1,ar[pos].back()-'a',prevFirstChar);
        }else{
            conc = curLen+rec(ar,pos+1,ar[pos].back()-'a',prevFirstChar);
        }
        if(ar[pos].back()-'a'==prevFirstChar){
            swapConc = curLen-1+rec(ar,pos+1,prevLastChar,ar[pos][0]-'a');
        }else{
            swapConc = curLen+rec(ar,pos+1,prevLastChar,ar[pos][0]-'a');
        }
        return dp[pos][prevFirstChar][prevLastChar] = min(swapConc,conc);
    }

    int minimizeConcatenatedLength(vector<string>& ar) {
        memset(dp,-1,sizeof(dp));
        return rec(ar,1,ar[0].back()-'a',ar[0][0]-'a')+ar[0].size();
    }
};