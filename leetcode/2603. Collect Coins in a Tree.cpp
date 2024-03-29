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
    void deleteNode(int i,vector<set<int>> &edges){
        for(auto it:edges[i]){
            edges[it].erase(i);
        }
    }

    void v1Transformation(vector<int> &coins,vector<set<int>> &edges,unordered_set<int> &deletedNodes){
        queue<int> q;
        for(int i=0;i<edges.size();i++){
            if(edges[i].size()==1) q.push(i);
        }
        while (q.size()){
            int cur=q.front();
            q.pop();
            if(!coins[cur]){
                deleteNode(cur,edges);
                deletedNodes.insert(cur);
                int nextNode= *edges[cur].begin();
                if(edges[nextNode].size()==1){
                    q.push(nextNode);
                }
            }
        }
    }

    void v2Transformation(vector<int> &coins,vector<set<int>> &edges,unordered_set<int> &deletedNodes){
        queue<pii> q;
        for(int i=0;i<edges.size();i++){
            if(edges[i].size()==1) q.push({i,0});
        }
        while (q.size()){
            pii cur=q.front();
            q.pop();
            deleteNode(cur.first,edges);
            deletedNodes.insert(cur.first);
            if(!cur.second){
                int nextNode= *edges[cur.first].begin();
                if(edges[nextNode].size()==1){
                    q.push({nextNode,cur.second+1});
                }
            }
        }
    }

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& ar) {
        vector<set<int>> edges(coins.size());
        for(auto it:ar){
            edges[it[0]].insert(it[1]);
            edges[it[1]].insert(it[0]);
        }
        unordered_set<int> deletedNodes;
        v1Transformation(coins,edges,deletedNodes);
        v2Transformation(coins,edges,deletedNodes);
        return max(0,2*((int)coins.size()-(int)deletedNodes.size()-1));
    }
};