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
    int markDivNodes(vector<vector<int>> &edges,int k,int pos,int prev,bool *goodRoots,vector<int> &values){
        int subTreeSum = values[pos];
        for(auto it:edges[pos]){
            if(it!=prev){
                subTreeSum = (subTreeSum + markDivNodes(edges,k,it,pos,goodRoots,values))%k;
            }
        }
        if(subTreeSum%k==0) goodRoots[pos]=true;
        return subTreeSum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& ar, vector<int>& values, int k) {
        vector<vector<int>> edges(n,vector<int>());
        int ans=0;
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        for(auto &it:values) it%=k;
        bool *goodRoots = new bool[n]();
        markDivNodes(edges,k,0,-1,goodRoots,values);
        for(int i=0;i<n;i++){
            if(goodRoots[i]){
                ans++;
            }
        }
        return ans;
    }
};