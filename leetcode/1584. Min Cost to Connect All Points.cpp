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
    int getDis(vector<int> &x,vector<int> &y){
        return abs(x[0]-y[0])+abs(x[1]-y[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& ar) {
        int n=ar.size(),ans=0;
        vector<vector<pii>> edges(n);      //  {idx,dis}
        bool *vis=new bool[n]();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                edges[i].push_back({j,getDis(ar[i],ar[j])});
                edges[j].push_back({i,getDis(ar[i],ar[j])});
            }
        }
        priority_queue<pii,vector<pii>,greater<pii>> q;       //  {dis,idx}
        q.push({0,0});
        while (q.size()){
            pii cur=q.top();          //  {dis,idx}
            q.pop();
            if(vis[cur.second]) continue;
            ans+=cur.first;
            vis[cur.second]=true;
            for(auto it:edges[cur.second]){
                if(!vis[it.first]) q.push({it.second,it.first});
            }
        }
        return ans;
    }
};