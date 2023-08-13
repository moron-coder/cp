#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& ar, int n, int k) {
        int ans=-1;
        vector<vector<pii>> edges(n,vector<pii>());
        for(auto it:ar) edges[it[0]].push_back({it[1]-1,it[2]});  //  {idx,dis}
        bool *vis=new bool[n]();
        k--;
        priority_queue<pii,vector<pii>,greater<pii>> pq;    //  {dis,idx}
        pq.push({0,k-1});
        while(pq.size()){
            pii tp=pq.top();
            pq.pop();
            if(vis[tp.second]) continue;
            cout<<tp.second<<" vis\n";
            vis[tp.second]=true;
            ans=max(ans,tp.first);
            for(auto it:edges[tp.second]) if(!vis[it.first]) pq.push({tp.first+it.second,it.first});
        }
        for(int i=0;i<n;i++) if(!vis[i]) return -1;
        return ans;
    }
};