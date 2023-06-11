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
    int rec(vector<vector<int>> &edges,int pos,vector<int> &informTime){
        int ans=0,added=0;
        for(auto it:edges[pos]){
            int sm = rec(edges,it,informTime)+informTime[pos];
            ans=max(ans,sm);
        }
        return ans;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> edges(n,vector<int>());
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1) edges[manager[i]].push_back(i);
        }
        return rec(edges,headID,informTime);
    }
};