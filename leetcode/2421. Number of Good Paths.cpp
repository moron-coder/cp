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

class uf{
   public:
   int *par,*rank;
   uf(int n){
    par=new int[n];
    rank=new int[n]();
    for(int i=0;i<n;i++) par[i]=i;
   } 

    int getPar(int x){
        if(par[x]==x) return x;
        return par[x]=getPar(par[x]);
    }

    void uni(int x,int y){
        x=getPar(x),y=getPar(y);
        if(rank[x]>rank[y]){
            par[y]=x,rank[x]+=rank[y];
        }
        else if(rank[y]>rank[x]){
            par[x]=y,rank[y]+=rank[x];
        }
        else{
            par[x]=y;
            rank[y]++;
        }
    }

};

class Solution {
public:
    void mergeNodes(vector<vector<int>> &edges,vector<int> &vals,int idx,uf &unn,int curVal){
        for(auto it:edges[idx]){
            if(vals[it]<=curVal){
                unn.uni(idx,it);
            }
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& ar) {
        int n=vals.size();
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        map<int,vector<int>> mp;
        uf unn(n);
        int ans=0;
        for(int i=0;i<n;i++) mp[vals[i]].push_back(i);
        for(auto it:mp){
            for(auto idx:it.second){
                mergeNodes(edges,vals,idx,unn,it.first);
            }
            map<int,int> parentsOfitFirst;
            for(auto idx:it.second){
                int curPar=unn.getPar(idx);
                parentsOfitFirst[curPar]++;
            }
            for(auto it:parentsOfitFirst){
                ans+=(it.second*(it.second+1))/2;
            }
        }
        return ans;
    }
};