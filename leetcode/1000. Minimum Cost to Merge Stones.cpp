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
    const int MAX_ANS = 10000;
    int dp[31][31][31];

    int help(vector<int> &ar,int pos,int en, int req,int k, vector<int> &pre){
        int n=en-pos+1;
        if(pos>=ar.size() || req==0) return 0;
        if(dp[pos][en][req]!=-1) return dp[pos][en][req];
        if(req==1){
            if(n==1){
                return 0;
            }else if(((n-1)%(k-1))==0){
                int ans = help(ar,pos,en,k,k,pre)+pre[en];
                if(pos) ans-=pre[pos-1];
                return ans;
            }
            return MAX_ANS;
        }
        int ans=MAX_ANS;
        for(int tmp=pos;tmp<en;tmp++){
            int c1 = help(ar,pos,tmp,1,k,pre) + help(ar,tmp+1,en,req-1,k,pre);
            ans=min(ans,c1);
        }
        return dp[pos][en][req] = ans;
    }
public:
    int mergeStones(vector<int>& ar, int k) {
        memset(dp,-1,sizeof(dp));
        int n=ar.size();
        if((n-1)%(k-1)) return -1;
        vector<int> pre(n,ar[0]);
        for(int i=1;i<n;i++) pre[i]=ar[i]+pre[i-1];
        return help(ar,0,n-1,1,k,pre);
    }
};