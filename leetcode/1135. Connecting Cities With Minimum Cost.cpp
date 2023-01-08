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
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<vector<pii>> edges(n,vector<pii>());     //  {index,cost}
        for(auto it:connections){
            edges[it[0]-1].push_back({it[1]-1,it[2]});
            edges[it[1]-1].push_back({it[0]-1,it[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;//  {cost,index}
        bool *vis=new bool[n]();
        pq.push({0,0});
        int ans=0;
        vector<int> costs(n,INT_MAX);
        costs[0]=0;
        while (pq.size()){
            pii cur=pq.top();
            pq.pop();
            int curNode=cur.second,curNodeCost=cur.first;
            if(vis[curNode]) continue;
            vis[curNode]=true;
            costs[curNode]=curNodeCost;
            for(auto it:edges[curNode]){
                int nextNode=it.first,nextNodeCost=it.second;
                if(!vis[nextNode]){
                    pq.push({nextNodeCost,nextNode});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return -1;
            ans+=costs[i];
        }
        return ans;
    }
};