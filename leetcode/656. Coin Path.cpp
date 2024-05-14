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
    int dp[1001];
    int bestIdx[1001];
    const static int MAX_ANS = 10000000;

    int help(vector<int>& coins, int &maxJump,int pos){
        int n=coins.size();
        if(pos==n-1){
            return 0;
        }
        if(dp[pos]!=-1) return dp[pos];
        int ans=MAX_ANS;
        for(int i=pos+1;i<=min(pos+maxJump,n-1);i++){
            if(coins[i]!=-1){
                int tmp = coins[i]+help(coins,maxJump,i); 
                if(tmp<ans){
                    ans = tmp;
                    bestIdx[pos]=i;
                }
            }
        }
        return dp[pos] = min(MAX_ANS, ans);
    }

public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        memset(dp,-1,sizeof(dp));
        memset(bestIdx,-1,sizeof(bestIdx));
        int ans = help(coins, maxJump, 0);
        if(ans==MAX_ANS){
            return {};
        }
        int ptr=0;
        vector<int> ret(1,1);
        while (ptr!=coins.size()-1){
            cout<<" from "<<ptr<<" to "<<bestIdx[ptr]<<endl;
            ptr=bestIdx[ptr];
            ret.push_back(ptr+1);
        }
        return ret;
    }
};