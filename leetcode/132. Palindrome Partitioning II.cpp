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
    bool isPal[2001][2001];
    int dp[2001];

    void getPalStretchOdd(string &s,int i){
        for(int len=1;len+i-1<s.size() && i-len+1>=0 && s[i-len+1]==s[i+len-1];len++){
            isPal[i-len+1][i+len-1]=true;
        }
    }

    void getPalStretchEven(string &s,int i){
        for(int j=i+1;j<s.size() && i>=0 && s[i]==s[j];i--,j++){
            isPal[i][j]=true;
        }
    }
    
    void getPalStretch(string &s,int i){
        getPalStretchOdd(s,i);
        getPalStretchEven(s,i);
    }


    int help(string &s,int i){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=s.size()-i;
        for(int j=i;j<s.size();j++){
            if(isPal[i][j]){
                ans = min(ans, 1+help(s,j+1));
            }
        }
        return dp[i] = ans;
    }

public:
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        for(int i=0;i<n;i++){
            getPalStretch(s,i);
        }
        return help(s,0)-1;
    }
};