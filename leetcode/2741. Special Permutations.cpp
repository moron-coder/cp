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
    int dp[1<<14][15];

    int rec(vector<int> &ar,int conf,int prevPos){
        if(dp[conf][prevPos+1]!=-1) return dp[conf][prevPos+1];
        int n=ar.size();
        if(conf==((1<<n)-1)){
            return 1;
        }
        int ans=0;
        for(int i=0;i<ar.size();i++){
            if((conf&(1<<i))==0){
                if(prevPos==-1 || ar[i]%ar[prevPos]==0 || ar[prevPos]%ar[i]==0){
                    ans = (ans+rec(ar,conf^(1<<i),i))%mod;
                }
            }
        }
        return dp[conf][prevPos+1] = ans%mod;
    }

    int specialPerm(vector<int>& ar) {
        memset(dp,-1,sizeof(dp));
        return rec(ar,0,-1);
    }
};