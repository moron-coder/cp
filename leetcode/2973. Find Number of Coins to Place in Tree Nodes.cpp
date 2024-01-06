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

class tup{
    public:
    vector<int> lows;   //  lows[0]<=lows[1]
    vector<int> highs;   //  highs[0]<=highs[1]<=highs[2]
    tup(int x){
        lows.push_back(x);
        lows.push_back(0);

        highs.push_back(0);
        highs.push_back(0);
        highs.push_back(x);
    }

    void injestLo(int x){
        if(x<lows[0]){
            lows[1]=lows[0];
            lows[0]=x;
        }else if(lows[1]==0 || x<lows[1]){
            lows[1]=x;
        }
    }

    void injestHi(int x){
        if(x>highs[2]){
            highs[0]=highs[1];
            highs[1]=highs[2];
            highs[2]=x;
        }else if(highs[1]==0 || x>highs[1]){
            highs[0]=highs[1];
            highs[1]=x;
        }else if(highs[0]==0 || x>highs[0]){
            highs[0]=x;
        }
    }
};

class Solution {
public:
    vector<long long> ret;

    tup help(vector<vector<int>> &edges,vector<int> &cost,int prev,int pos){

        tup curVals(cost[pos]);
        for(auto it:edges[pos]){
            if(it!=prev){
                tup sm = help(edges,cost,pos,it);
                for(auto it1:sm.lows){
                    if(it1) {
                        curVals.injestLo(it1);
                    }
                }
                for(auto it1:sm.highs){
                    if(it1){
                        curVals.injestHi(it1);
                    }
                }
            }
        }


        long long ansVal=1;
        long long prd=1;
        if(curVals.highs[0]) prd = max({0LL,1LL*curVals.highs[2]*curVals.highs[1]*curVals.highs[0],1LL*curVals.highs[2]*curVals.lows[0]*curVals.lows[1]});
        ret[pos]=prd;
        return curVals;
    }

    vector<long long> placedCoins(vector<vector<int>>& ar, vector<int>& cost) {
        int n=cost.size();
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++) ret.push_back(1);
        help(edges,cost,-1,0);
        return ret;
    }
};