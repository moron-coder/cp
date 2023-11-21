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
    long long help(vector<vector<int>> &edges,int pos,int prev,int minValIdx,vector<int> &values){
        if(prev!=-1 && edges[pos].size()==1){
            return values[pos];
        }
        long long ans = values[minValIdx],small=0;
        for(auto it:edges[pos]){
            long long newMinValIdx=(values[it]<values[minValIdx])?it:minValIdx;
            if(it!=prev) small+=help(edges,it,pos,newMinValIdx,values);
        }
        return min(ans,small);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& ar, vector<int>& values) {
        int n=values.size();
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        long long sum=0;
        for(auto it:values) sum+=it;
        return sum-help(edges,0,-1,0,values);
    }
};