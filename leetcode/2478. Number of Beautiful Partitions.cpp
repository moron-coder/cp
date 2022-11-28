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
    bool ok1(string &s,int st){
        return (s[st]=='2' || s[st]=='3' || s[st]=='5' || s[st]=='7');
    }

    bool ok2(string &s,int en){
        return (en<s.size() && s[en]!='2' && s[en]!='3' && s[en]!='5' && s[en]!='7');
    }   

    int beautifulPartitions(string s, int k, int minLength) {
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        // dp[i][j]-> no of combinations with s[i]~s[n-1] in which substring is divided into j parts
        int n=s.size();
        for(int j=0;j<=k;j++) dp[n-1][j]=0;
        for(int i=n-2;i>=0;i--){
            dp[i][0]=0;
            dp[i][1]=(ok1(s,i) && ok2(s,n-1) && n-i>=minLength);
        }
        dp[n][0]=1;
        for(int j=2;j<=k;j++){
            int suf=0;
            for(int i=n-2;i>=0;i--){
                int cur=0;
                if(ok2(s,i+minLength-1)) cur=dp[i+minLength][j-1];
                if(ok1(s,i)){
                    dp[i][j]=suf;
                    if(ok2(s,i+minLength-1)) dp[i][j]=(dp[i][j]+dp[i+minLength][j-1])%mod;
                }
                suf=(suf+cur)%mod;
            }
        }
        return dp[0][k];
    }
};