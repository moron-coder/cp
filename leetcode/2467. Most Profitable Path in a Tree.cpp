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
    bool calcDis(vector<vector<int>> &edges, int pos, int prev, vector<pii> &dis){
        bool canReachZero=(pos==0);
        for(auto it:edges[pos]){
            if(it!=prev){
                dis[it].first=dis[pos].first+1;
                bool sm=calcDis(edges,it,pos,dis);
                canReachZero = (canReachZero || sm);
            }
        }
        return dis[pos].second=canReachZero;
    }

    int optimalLeafPath(vector<vector<int>> &edges,int pos,int prev,vector<int> &amount){
        int maxPath = INT_MIN;
        for(auto it:edges[pos]){
            if(it!=prev){
                int sm=optimalLeafPath(edges,it,pos,amount);
                maxPath=max(maxPath,sm+amount[pos]);
            }
        }
        return (maxPath==INT_MIN)?amount[pos]:maxPath;
    }

    int mostProfitablePath(vector<vector<int>>& ar, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        vector<pii> aliceDis(n),bobDis(n);
        for(int i=0;i<n;i++){
            aliceDis[i]={-1,-1};
            bobDis[i]={-1,-1};
        }
        aliceDis[0]={0,true};
        bobDis[bob]={0,true};
        // change amounts of those nodes which will be affected by Bob
        // Then the problem reduces to find max points to reach leaf node
        calcDis(edges,0,-1,aliceDis);
        calcDis(edges,bob,-1,bobDis);
        for(int i=0;i<n;i++){
            if(aliceDis[i].first>bobDis[i].first && bobDis[i].second) amount[i]=0;
            else if(aliceDis[i].first==bobDis[i].first && bobDis[i].second) amount[i]/=2;
        }
        return optimalLeafPath(edges,0,-1,amount);
    }
};