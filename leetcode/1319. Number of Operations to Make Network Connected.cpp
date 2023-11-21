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
    pii dfs(int pos,vector<vector<int>> &edges,bool *vis){
        int edgesCount=0, verticesCount=0;
        for(auto it:edges[pos]){
            if(!vis[it]){
                pii small = dfs(it,edges,vis);
                edgesCount+=small.first, verticesCount+=small.second;
            }
        }
        vis[pos]=true;
        return {edgesCount+edges[pos].size(),verticesCount+1};
    }

    int makeConnected(int n, vector<vector<int>>& ar) {
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        bool *vis = new bool[n]();
        int ct=0;
        vector<pii> counts;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                pii small = dfs(i,edges,vis);
                counts.push_back(small);
            }
        }
        if(counts.size()==1) return 0;
        for(auto it:counts){
            if(it.first==it.second-1) return -1;
        }
        return counts.size()-1;
    }
};