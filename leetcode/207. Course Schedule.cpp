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
    stack<int> stk;
    bool vis[2001];
    
    bool isCyc(vector<vector<int>> &edges,int pos,vector<int> &states){
        if(states[pos]==1){
            return true; 
        }
        states[pos]=1;
        for(auto it:edges[pos]){
            if(states[it]!=2 && isCyc(edges,it,states)){
                return true;
            }
        }
        states[pos]=2;
        return false;
    }
        
    bool canFinish(int n, vector<vector<int>>& adj) {
        for(int i=0;i<=2000;i++) vis[i]=false;
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:adj){
            edges[it[1]].push_back(it[0]);
        }
        while (stk.size()) stk.pop();
        vector<int> states(n,0);
        for(int i=0;i<n;i++){
            if(isCyc(edges,i,states)) return false;
        }
        return true;
    }
};