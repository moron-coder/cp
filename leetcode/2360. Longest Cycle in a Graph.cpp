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
    int ans;

    void dfs(vector<int> &edges,int pos,vector<int> &states,int *mp,int ct){
        int nxt=edges[pos];
        mp[pos]=ct;
        states[pos]=1;
        if(states[nxt]==0){
            dfs(edges,nxt,states,mp,ct+1);
        }else if(states[nxt]==1){
            ans=max(ans,ct+1-mp[nxt]);
        }else{
            // ignore
        }
        states[pos]=2;
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int *mp=new int[n]();
        ans=0;
        vector<int> states(n,0);
        for(int i=0;i<n;i++) if(!states[i]) dfs(edges,i,states,mp,0);
        return ans;
    }
};