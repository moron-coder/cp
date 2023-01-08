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


    void bfs(vector<vector<int>> &edges,vector<int> &t,int curTime,int pos,int *inTime,unordered_map<int,unordered_set<int>> &parents){
        for(auto it:edges[pos]){
            if(parents[it].count(pos) && !parents[pos].size()){
                //  it means we haven't travelled from 'pos' to 'it'
                //  so, update the in time of 'it' and travel to 'it'
                //  also, make sure that we don't travel to 'it' again else it
                //  would increase the time complexity
                inTime[it]=max(inTime[it],inTime[pos]+t[pos]);
                parents[it].erase(pos);
                if(parents[it].empty()) bfs(edges,t,curTime,it,inTime,parents);
            }
        }
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& t) {
        vector<vector<int>> edges(n,vector<int>());
        int *inTime=new int[n]();
        unordered_map<int,unordered_set<int>> parents;
        for(auto it:relations){
            edges[it[0]-1].push_back(it[1]-1);
            parents[it[1]-1].insert(it[0]-1);
        }
        for(int i=0;i<n;i++){
            if(!parents[i].size()){
                bfs(edges,t,0,i,inTime,parents);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans,inTime[i]+t[i]);
        return ans;
    }
};