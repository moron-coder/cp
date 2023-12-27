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
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //  start from src, do bfs
        unordered_map<int,vector<int>> stopToRoutes;
        queue<int> q;
        for(int i=0;i<routes.size();i++){
            for(auto it:routes[i]){
                stopToRoutes[it].push_back(i);
            }
        }
        int n=routes.size();
        vector<queue<int>> qRoutes(n);
        for(int i=0;i<routes.size();i++){
            for(auto it:routes[i]){
                qRoutes[i].push(it);
            }
        }
        unordered_set<int> vis;
        q.push(source);
        vis.insert(source);
        q.push(-1);
        int steps=0;
        while (q.size()){
            int cur=q.front();
            q.pop();
            if(cur==-1){
                if(q.empty()) q.pop();
                q.push(-1);
                steps++;
            }else{
                if(cur==target) return steps;
                for(auto it:stopToRoutes[cur]){
                    while(qRoutes[it].size()){
                        if(!vis.count(qRoutes[it].front())){
                            q.push(qRoutes[it].front());
                            vis.insert(qRoutes[it].front());
                        }
                        qRoutes[it].pop();
                    }
                }
            }
        }
        return -1;
    }
};