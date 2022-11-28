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
    ll ans;

    pll dfs(vector<vector<int>> &edges,int pos,vector<bool> &vis,int &seats){
        // returns {no of taxi,no of seats occuppied}
        ll curAns=0;
        vis[pos]=true;
        int carsCt=0,passengerCt=0;
        for(auto it:edges[pos]){
            if(!vis[it]){
                pll tmp=dfs(edges,it,vis,seats);
                passengerCt+=tmp.second;
                carsCt+=tmp.first;
                curAns+=tmp.first+(tmp.second!=0);
            }
        }
        carsCt+=(passengerCt+1)/seats,passengerCt=(passengerCt+1)%seats;
        ans+=curAns;
        return {carsCt,passengerCt};
    }

    long long minimumFuelCost(vector<vector<int>>& ar,int seats) {
        int n=ar.size()+1;
        vector<vector<int>> edges(n);
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        ans=0;
        vector<bool> vis(n,false);
        dfs(edges,0,vis,seats);
        return ans;
    }
};