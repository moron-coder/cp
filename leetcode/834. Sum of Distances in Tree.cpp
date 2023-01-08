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
    pii help(vector<vector<int>> &edges,int pos,bool *vis,int *ch){
        pii ans={1,0};      //  {number of nodes,sum}
        for(auto it:edges[pos]){
            if(!vis[it]){
                vis[it]=true;
                pii small = help(edges,it,vis,ch);
                ans.first+=small.first,ans.second+=small.second+small.first;
            }
        }
        ch[pos]=ans.first;
        return ans;
    }

    void getAns(vector<vector<int>> &edges,int *ch,vector<int> &ans,bool *vis,int pos,int parSum){
        if(pos) ans[pos]=edges.size()+parSum-2*ch[pos];
        for(auto it:edges[pos]){
            if(!vis[it]){
                vis[it]=true;
                getAns(edges,ch,ans,vis,it,ans[pos]);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& ar) {
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        bool *vis=new bool[n]();
        int *ch=new int[n]();
        vector<int> ans(n,0);
        // we can consider any node as root and start recursion
        // let's start from 0
        vis[0]=true;
        pii zAns = help(edges,0,vis,ch);
        for(int i=0;i<n;i++) vis[i]=false;
        vis[0]=true;
        ans[0]=zAns.second;
        getAns(edges,ch,ans,vis,0,zAns.second);
        return ans;
    }
};