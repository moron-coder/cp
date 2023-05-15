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
    void markVis(vector<vector<int>> &edges,int *vis,int cur,int visOrder,vector<unordered_set<int>> &visOrderNodes){
        vis[cur]=visOrder;
        visOrderNodes[visOrder-1].insert(cur);
        for(auto it:edges[cur]){
            if(!vis[it]){
                markVis(edges,vis,it,visOrder,visOrderNodes);
            }
        }
    }

    bool checkConnectedComp(vector<vector<int>> &edges,int pos,int visOrder,vector<unordered_set<int>> &visOrderNodes){
        for(auto it:visOrderNodes[visOrder-1]){
            if(edges[it].size()!=visOrderNodes[visOrder-1].size()-1) return false;
        }
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& ar) {
        int ans=0;
        vector<vector<int>> edges(n,vector<int>()); 
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        int *vis=new int[n]();
        int visOrder=1;
        vector<unordered_set<int>> visOrderNodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                unordered_set<int> tmp;
                visOrderNodes.push_back(tmp);
                markVis(edges,vis,i,visOrder,visOrderNodes);
                if(checkConnectedComp(edges,i,visOrder,visOrderNodes)) ans++;
                visOrder++;
            }
        }
        return ans;
    }
};