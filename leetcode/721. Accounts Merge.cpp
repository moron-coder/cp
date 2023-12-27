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

class DSU{
    public:
    int *rank,*par;

    DSU(int n){
        rank=new int[n]();
        par=new int[n]();
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int getPar(int x){
        while (par[x]!=x) x=par[x];
        return x;
    }

    void merge(int x,int y){
        int px=getPar(x),py=getPar(y);
        if(rank[px]<rank[py]){
            par[px]=py;
            rank[py]+=rank[px];
        }else{
            par[py]=px;
            rank[px]+=rank[py];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                mp[accounts[i][j]].push_back(i);
            }
        }
        for(auto it:mp){
            int x=it.second[0];
            for(int j=1;j<it.second.size();j++){
                int y=it.second[j];
                dsu.merge(x,y);
            }
        }
        unordered_map<int,set<string>> ansMap;
        for(int i=0;i<accounts.size();i++){
            int parId = dsu.getPar(i);
            for(int j=1;j<accounts[i].size();j++){
                ansMap[parId].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(auto it:ansMap){
            vector<string> cur;
            cur.push_back(accounts[it.first][0]);
            for(auto it1:it.second){
                cur.push_back(it1);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};