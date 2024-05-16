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
    int dp[20001][2];

    bool help(vector<int> &ar, vector<int> &sufSmalls, vector<int> &sufBigs,int pos, bool isOddJump){
        int n=ar.size();
        if(pos==ar.size()-1){
            return true;
        }
        if(dp[pos][isOddJump]!=-1) return dp[pos][isOddJump];
        bool isGoodIdx=true;
        if(isOddJump){
            int nextIdx = sufBigs[pos];
            if(nextIdx==-1){
                return false;
            }else{
                isGoodIdx = help(ar,sufSmalls,sufBigs,nextIdx,!isOddJump);
            }
        }else{
            int nextIdx = sufSmalls[pos];
            if(nextIdx==-1){
                return false;
            }else{
                isGoodIdx = help(ar,sufSmalls,sufBigs,nextIdx,!isOddJump);
            }
        }
        return dp[pos][isOddJump] = isGoodIdx;
    }

    void makeSufBigs(vector<int> &ar, vector<int> &sufBigs){
        int n=ar.size();
        map<int,int> mp;        //  {val, index}

        for(int i=n-1;i>=0;i--){
            auto it = mp.lower_bound(ar[i]);
            if(it!=mp.end()){
                sufBigs[i] = it->second;
            }
            mp[ar[i]]=i;
        }
    }

    void makeSufSmalls(vector<int> &ar, vector<int> &sufSmalls){
        int n=ar.size();
        map<int,int> mp;        //  {val, index}

        for(int i=n-1;i>=0;i--){
            auto it = mp.lower_bound(-ar[i]);
            if(it!=mp.end()){
                sufSmalls[i]=it->second;
            }
            mp[-ar[i]]=i;
        }
    }

public:

    int oddEvenJumps(vector<int>& ar) {
        memset(dp,-1,sizeof(dp));
        int n=ar.size();
        vector<int> sufBigs(n,-1), sufSmalls(n,-1);   
        makeSufBigs(ar,sufBigs);
        makeSufSmalls(ar,sufSmalls);
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=help(ar,sufSmalls,sufBigs,i,true);
        }
        return ans;
    }
};