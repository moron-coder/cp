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
    int ul;

    bool help(vector<int> &oddNodes,int pos,int &vis,vector<unordered_set<int>> &edges){
        int n=edges.size(),oN=oddNodes.size();
        if(pos>=oN) return vis==ul;
        if(vis&(1<<pos)) return help(oddNodes,pos+1,vis,edges);
        vis=(vis^(1<<pos));
        int curNode=oddNodes[pos];
        for(int i=0;i<oN;i++){
            int newNode=oddNodes[i];
            if(i==pos || (vis&(1<<i)) || edges[curNode].count(newNode)) continue;
            vis=(vis^(1<<i));
            if(help(oddNodes,pos+1,vis,edges)) return true;
            vis=(vis^(1<<i));
        }
        vis=(vis^(1<<pos));
        return false;
    }

    bool isPossible(int n, vector<vector<int>>& ar) {
        vector<unordered_set<int>> edges(n,unordered_set<int>());
        for(auto it:ar){
            edges[it[0]-1].insert(it[1]-1);
            edges[it[1]-1].insert(it[0]-1);
        }
        vector<int> oddNodes;
        for(int i=0;i<n;i++) if(edges[i].size()%2) oddNodes.push_back(i);
        if(oddNodes.size()==0) return true;
        else if(oddNodes.size()==2){
            if(!edges[oddNodes[0]].count(oddNodes[1])){
                return true;
            }
            for(int i=0;i<n;i++){
                if(i==oddNodes[0] || i==oddNodes[1]) continue;
                if(!edges[oddNodes[0]].count(i) && !edges[oddNodes[1]].count(i)){
                    return true;
                }
            }
            return false;
        }else if(oddNodes.size()!=4) return false;
        ul=(oddNodes.size()==2)?3:15;
        int vis=0;
        return help(oddNodes,0,vis,edges);
    }
};
