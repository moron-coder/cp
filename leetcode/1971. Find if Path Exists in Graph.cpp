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
    int dp[200001];
public:
    bool help(vector<vector<int>> &edges,int pos,int des){
        if(pos==des) return true;
        dp[pos]=1;
        for(auto it:edges[pos]){
            if(dp[it]==0 && help(edges,it,des)){
                return true;
            }
        }
        dp[pos]=2;
        return false;
    }

    bool validPath(int n, vector<vector<int>>& ar, int source, int destination) {
        memset(dp,0,sizeof(dp));
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        return help(edges,source,destination);
    }
};