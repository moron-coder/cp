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
    int dfs(vector<vector<int>> &edges, int pos, bool *vis){
        int ans = 1;
        for(auto it:edges[pos]){
            if(!vis[it]){
                vis[it]=true;
                ans+=dfs(edges, it, vis);
            }
        }
        return ans;
    }

public:
    long long countPairs(int n, vector<vector<int>>& ar) {
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        long long ans=0,tot=0;
        vector<int> sz;
        bool *vis = new bool[n]();
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                int tmp = dfs(edges, i, vis);
                sz.push_back(tmp);
                tot+=tmp;
            }
        } 
        for(auto it:sz){
            ans+=(tot-it)*it;
        }
        return ans;
    }
};