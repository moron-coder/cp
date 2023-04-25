#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define piv pair<int, vector<int>>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int

class Solution {
public:
    void topSort(vector<vector<int>> &edges,int idx,vector<int> &stk, bool *vis){
        for(auto it:edges[idx]) if(!vis[it]) topSort(edges,it,stk,vis);
        stk.push_back(idx);
        vis[idx]=true;
    }

    void buildAncestorList(vector<vector<int>> &parent,vector<vector<int>> &ans,int cur,int par,bool **isAncestorVisited){
        ans[cur].push_back(par);
        isAncestorVisited[cur][par]=true;
        for(auto it:parent[par]){
            if(!isAncestorVisited[cur][it]){
                buildAncestorList(parent,ans,cur,it,isAncestorVisited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edgeList) {
        vector<vector<int>> edges(n,vector<int>());
        bool *vis=new bool[n]();
        vector<int> topSortOrder;
        for(auto it:edgeList) edges[it[0]].push_back(it[1]);
        for(int i=0;i<n;i++) if(!vis[i]) topSort(edges, i, topSortOrder, vis);
        reverse(topSortOrder.begin(),topSortOrder.end());
        vector<vector<int>> ans(n,vector<int>()),parent(n,vector<int>());
        bool **isAncestorVisited=new bool*[n];
        for(int i=0;i<n;i++) isAncestorVisited[i]=new bool[n]();
        for(int i=0;i<topSortOrder.size();i++){ 
            for(auto it:edges[topSortOrder[i]]) parent[it].push_back(topSortOrder[i]);
        }
        for(int i=0;i<n;i++){
            for(auto par:parent[i]){
                buildAncestorList(parent,ans,i,par,isAncestorVisited);
            }
        }
        for(auto &it:ans) sort(it.begin(),it.end());
        return ans;
    }
};