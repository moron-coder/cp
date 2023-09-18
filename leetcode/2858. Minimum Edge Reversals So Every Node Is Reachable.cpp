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
    int dfs(vector<vector<pii>> &edges,int pos,int prev){
        int ans=0;
        for(auto it:edges[pos]){
            if(prev!=it.first){
                ans+=dfs(edges,it.first,pos)+it.second;
            }
        }
        return ans;
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& ar) {
        int *vis = new int[n]();
        map<pii,int> mp;
        vector<vector<pii>> edges(n,vector<pii>());
        for(auto it:ar){
            edges[it[0]].push_back({it[1],0});
            edges[it[1]].push_back({it[0],1});
        }
        vector<int> ans(n,0);
        int zAns = dfs(edges,0,-1);
        ans[0]=zAns;
        for(auto it:edges[0]){
            reroot(edges,it.first,0,it.second,ans,zAns);
        }
        return ans;
    }

    void reroot(vector<vector<pii>> &edges,int pos,int prev,int del,vector<int> &ans,int prevAns){
        // prevAns is the cost of traversing to all nodes from prev
        if(del==1){
            prevAns--;      //  it'll take 1 less cost to go from pos to prev
        }else{
            prevAns++;      //  it'll take 1 more cost to go from pos to prev
        }
        ans[pos]=prevAns;
        for(auto it:edges[pos]){
            if(prev!=it.first){
                reroot(edges,it.first,pos,it.second,ans,prevAns);
            }
        }
    }
};