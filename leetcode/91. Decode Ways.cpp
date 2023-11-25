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
    int dp[100001];

    int help(string &s,int pos){
        if(pos>=s.size()){
            return 1;
        }
        if(dp[pos]!=-1) return dp[pos];
        if(s[pos]=='0'){
            return 0;
        }
        string small;
        small.push_back(s[pos]);
        int ans = help(s,pos+1);
        if(pos+1<s.size()){
            small.push_back(s[pos+1]);
            if(stoi(small)<=26){
                ans = (ans+help(s,pos+2));
            }
        }
        return dp[pos] = ans;
    }

    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return help(s,0);
    }
};