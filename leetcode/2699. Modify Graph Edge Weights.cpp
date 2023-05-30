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
    const static int INF=2000000000;
    bool shortCircuit;

    bool rec(vector<vector<pii>> &edges,int cur,int des,vector<vector<int>> &ar,int addedEdge,int tg,bool *vis){
        vis[cur]=true;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,cur});
        while (pq.size()){
            vector<int> cur=pq.top();
            pq.pop();
            vis[cur[1]]=true;

            if(cur[1]==des){
                if(cur[0]<=tg){
                    if(addedEdge==-1){
                        if(cur[0]==tg){
                            for(auto &it:ar) if(it[2]==-1) it[2]=INF;
                            return true;
                        }else if(cur[0]<tg){
                            shortCircuit=true;
                            return false;
                        }
                    }else{
                        ar[addedEdge][2]+=tg-cur[0];
                        for(auto &it:ar) if(it[2]==-1) it[2]=INF;
                        return true;
                    }
                }
                return false;
            }

            for(auto it:edges[cur[1]]){
                if(!vis[it.first]) pq.push({cur[0]+it.second,it.first});
            }
        }
        return false;
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& ar, int source, int destination, int target) {
        shortCircuit=false;
        vector<vector<pii>> edges(n,vector<pii>());
        for(auto it:ar){
            if(it[2]!=-1){
                edges[it[0]].push_back({it[1],it[2]});
                edges[it[1]].push_back({it[0],it[2]});
            }
        }
        bool *vis=new bool[n]();
        if(rec(edges,source,destination,ar,-1,target,vis)){
            return ar;
        }
        if(shortCircuit) return {};
        for(int i=0;i<ar.size();i++){
            if(ar[i][2]==-1){
                ar[i][2]=1;
                vis=new bool[n]();
                edges[ar[i][0]].push_back({ar[i][1],1});
                edges[ar[i][1]].push_back({ar[i][0],1});
                if(rec(edges,source,destination,ar,i,target,vis)){
                    return ar;
                }
            }
        }
        return {};
    }
};