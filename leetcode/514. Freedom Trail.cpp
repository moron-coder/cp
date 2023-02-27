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

int dp[101][101];

class Solution {
public: 
    int help(string &s,string &t,int tPos,int btnPos){
        if(tPos>=t.size()){
            return 0;
        }
        if(dp[tPos][btnPos]!=-1) return dp[tPos][btnPos];
        int ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[tPos]){
                ans=min(ans,1+min(abs(i-btnPos),(int)s.size()-abs(i-btnPos))+help(s,t,tPos+1,i));
            }
        }
        return dp[tPos][btnPos]=ans;
    }

    int findRotateSteps(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return help(s,t,0,0);
    }
};