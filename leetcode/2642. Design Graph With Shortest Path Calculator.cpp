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

class Graph {
    unordered_map<int,vector<pii>> mp;      //  {index, price}
public:
    Graph(int n, vector<vector<int>>& edges) {
        mp.clear();
        for(auto it:edges){
            mp[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        mp[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        unordered_set<int> vis;
        pq.push({0,node1});
        while (pq.size()){
            pii cur = pq.top();
            pq.pop();
            if(cur.second==node2){
                return cur.first;
            }
            vis.insert(cur.second);
            for(auto it:mp[cur.second]){
                if(vis.count(it.first)) continue;
                pq.push({cur.first+it.second,it.first});
            }
        }
        return -1;
    }
};