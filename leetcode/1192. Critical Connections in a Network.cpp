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
    vector<vector<int>> ans;
public:
    void dfs(vector<vector<int>> &edges,int pos,int prev,bool *vis,vector<int> &lowestTimes,int &curTime){
        lowestTimes[pos]=curTime;
        int lowestTime = curTime;
        vector<pii> lowestVisTimes;
        for(auto it:edges[pos]){
            if(!vis[it]){
                curTime++;
                vis[it]=true;
                dfs(edges,it,pos,vis,lowestTimes, curTime);
                if(lowestTimes[it]>lowestTimes[pos]){
                    ans.push_back({pos,it});
                }
            }
            if(it!=prev){
                lowestTime=min(lowestTime, lowestTimes[it]);
            }
        }
        lowestTimes[pos]=lowestTime;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& ar) {
        vector<vector<int>> edges(n);
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        vector<int> lowestTimes(n,-1);
        while (ans.size()){
            ans.pop_back();
        }
        bool *vis = new bool[n]();
        int curTime=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(edges,i,-1,vis,lowestTimes,curTime);
            }
        }
        return ans;
    }
};