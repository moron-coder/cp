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
    long dp[26][26];
public:
    void dij(vector<vector<pii>> &edges,int pos){
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        bool *vis = new bool[26]();
        pq.push({0,pos});
        while (pq.size()){
            pii cur=pq.top();
            pq.pop();
            long idx=cur.second,curCost=cur.first;
            if(vis[idx]) continue;
            vis[idx]=true;
            dp[pos][idx]=(dp[pos][idx]==-1)?curCost:min(curCost,dp[pos][idx]);
            for(auto it:edges[idx]){
                pq.push({it.second+curCost,it.first});
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        vector<vector<pii>> edges(26);
        for(int i=0;i<original.size();i++){
            edges[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        for(int i=0;i<26;i++){
            dij(edges,i);
        }
        long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            if(dp[source[i]-'a'][target[i]-'a']==-1){
                return -1;
            }
            ans+=dp[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};