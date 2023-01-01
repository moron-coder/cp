#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pbi pair<bool, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int

class Solution {
public:
    int minPath;

    void dfs(vector<vector<pii>> &edges,int pos,vector<bool> &vis){
        vis[pos]=true;
        for(auto it:edges[pos]){
            minPath=min(minPath,it.second);
            if(!vis[it.first]) dfs(edges,it.first,vis);
        }
    }

    int minScore(int n, vector<vector<int>>& ar) {
        vector<vector<pii>> edges(n,vector<pii>()); //  {point,distance}
        minPath=INT_MAX;
        for(auto it:ar){
            edges[it[0]-1].push_back({it[1]-1,it[2]});
            edges[it[1]-1].push_back({it[0]-1,it[2]});
        }
        vector<bool> vis(n,false);
        dfs(edges,0,vis);
        return minPath;
    }
};