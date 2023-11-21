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


class dsu{
    int getPar(int x){
        if(par[x]==x) return x;
        return par[x]=getPar(par[x]);
    }
    public:
    int *rank;
    int *par;

    dsu(int n){
        rank = new int[n]();
        par = new int[n]();
        for(int i=0;i<n;i++) par[i]=i;
    }

    void merge(int x,int y){
        int parX = getPar(x);
        int parY = getPar(y);
        if(parX==parY){
            return;
        }
        if(rank[parX]>rank[parY]){
            par[parY]=parX;
        }else if(rank[parY]>rank[parX]){
            par[parX]=parY;
        }else{
            par[parX]=parY;
            rank[parX]++;
            rank[parY]++;
        }
    }

};

class Solution {
public:
    int dfs(vector<vector<int>> &edges,int pos,int *vis){
        int cur=1;
        vis[pos]=1;
        for(auto it:edges[pos]) if(!vis[it]) cur+=dfs(edges,it,vis);
        cout<<pos<<" returns "<<cur<<endl;
        vis[pos]=2;
        return cur; 
    }

    int findChampion(int n, vector<vector<int>>& ar) {
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar) edges[it[0]].push_back(it[1]);
        for(int i=0;i<n;i++){
            int *vis = new int[n]();
            if(dfs(edges,i,vis)==n){
                return i;
            }
        }
        return -1;
    }
};