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
    int digCt(int n){
        if(n<=1) return 0;
        int ans=0;
        while (n){
            ans++;
            n/=10;
        }
        return ans;
    }

    int help(string &s,int pos,int k){
        int n=s.size();
        if(pos>=n){
            return 0;
        }
        if(dp[pos][k]!=-1) return dp[pos][k];
        int ans=10001;
        int fq=0;           //  due to s[pos]
        int originalK = k;
        for(int i=pos;i<n;i++){
            if(s[i]!=s[pos]){
                if(!k) break;
                k--;
            }else{
                fq++;
            }
            int curAns = 1+digCt(fq)+help(s,i+1,k);
            ans=min(ans,curAns);
        }
        return dp[pos][originalK] = ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int ans=10001,n=s.size();
        for(int i=0;i<=min(n,k);i++){
            ans=min(ans,help(s,i,k-i));
        }
        return ans;
    }
};