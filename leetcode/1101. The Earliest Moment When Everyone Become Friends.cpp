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
    void dfs(vector<vector<pii>> &edges,int pos,vector<bool> &vis,int t){
        vis[pos]=true;
        for(auto it:edges[pos]){
            if(!vis[it.first] && t>=it.second) dfs(edges,it.first,vis,t);
        }
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        int ans=INT_MAX;
        vector<vector<pii>> edges(n,vector<pii>());
        for(auto it:logs){
            edges[it[1]].push_back({it[2],it[0]});
            edges[it[2]].push_back({it[1],it[0]});
        }
        int hi=1000000001,lo=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            vector<bool> vis(n,false);
            dfs(edges,0,vis,mid);
            bool isOk=true;
            for(int i=0;i<n && isOk;i++){
                if(!vis[i]) isOk=false;
            }
            if(isOk){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};