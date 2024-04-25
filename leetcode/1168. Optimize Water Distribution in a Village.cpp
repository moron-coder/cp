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
    int *par, *rank;
    public:

    DSU(int n){
        par = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++){
            rank[i]=0;
            par[i]=i;
        }
    }

    int getPar(int x){
        while (par[x]!=x){
            return getPar(par[x]);
        }
        return x;
    }

    bool merge(int x,int y){
        int p1 = getPar(x), p2 = getPar(y);
        
        if(p1==p2){
            return false;
        }
        int r1 = rank[p1], r2 = rank[p2];

        if(r1<r2){
            par[p1]=p2;
            rank[p2]+=rank[p1];
        }else if(r1>r2){
            par[p2]=p1;
            rank[p1]+=rank[p2];
        }else{
            par[p2]=p1;
            rank[p1]++,rank[p2]++;
        }
        return true;
    }
};

class Solution {
    static bool cmp(vector<int> &v1,vector<int> &v2){
        return v1[2]<v2[2];
    }
public:
    void makePipesV2(vector<vector<int>> &pipes,vector<vector<int>> &ar){
        map<pii,int> mp;
        for(auto it:pipes){
            pii kv = {min(it[0],it[1]),max(it[0],it[1])};
            if(mp.count(kv)){
                mp[kv]=min(mp[kv],it[2]);
            }else{
                mp[kv]=it[2];
            }
        }
        for(auto it:mp){
            ar.push_back({it.first.first,it.first.second,it.second});
        }
    }

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i=0;i<n;i++){
            pipes.push_back({0,i+1,wells[i]});
        }
        vector<vector<int>> ar;
        makePipesV2(pipes,ar);
        sort(ar.begin(),ar.end(),cmp);

        for(auto it:ar){
            cout<<it[0]<<" -- "<<it[1]<<" -- "<<it[2]<<endl;
        }

        int ans=0;

        DSU disSet(n+1);

        for(auto it:ar){
            if(disSet.merge(it[0],it[1])){
                cout<<"join "<<it[0]<<" and "<<it[1]<<" at cost "<<it[2]<<endl;
                ans+=it[2];
            }
        }
        return ans;
    }
};