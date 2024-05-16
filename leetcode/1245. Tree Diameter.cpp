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
    pii bfsDis(int st, vector<vector<int>> &edges){
        int n=edges.size(),last=-1;
        bool *vis = new bool[n]();
        queue<int> q;
        int dis=0;
        q.push(st);
        vis[st]=true;
        q.push(-1);
        while (q.size()){
            int cur=q.front();
            q.pop();
            if(cur==-1){
                if(q.empty()) break;
                q.push(-1);
                dis++;
            }else{
                last=cur;
                for(auto it:edges[cur]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
        }
        return {dis,last};
    }

public:
    int treeDiameter(vector<vector<int>>& ar) {
        int n=ar.size()+1;
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        int st=-1;
        for(int i=0;i<n;i++){
            if(edges[i].size()==1){
                st=i;
            }
        }
        pii p1 = bfsDis(st,edges);
        pii p2 = bfsDis(p1.second,edges);

        return p2.first;
    }
};