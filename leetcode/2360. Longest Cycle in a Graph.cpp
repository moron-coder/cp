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
    void help(vector<int> &edges,int pos,int *vis,int *len,int curLen,int &greatestLen){
        if(vis[pos]==1){
            greatestLen = max(greatestLen,abs(curLen-len[pos]));
            return;
        }
        len[pos]=curLen;
        vis[pos]=1;
        if(edges[pos]!=-1 && vis[edges[pos]]!=2) help(edges,edges[pos],vis,len,curLen+1,greatestLen);
        vis[pos]=2;
    }

    int longestCycle(vector<int>& ar) {
        int n=ar.size(),ans=-1;
        int *vis = new int[n](),*len = new int[n]();        //  vis : 0(unvisited), 1(currently being visited), 2(already visited)
        for(int i=0;i<n;i++) vis[i]=-1;
        for(int i=0;i<n;i++){
            if(ar[i]!=-1 && vis[i]!=2){
                help(ar,i,vis,len,0,ans);
            }
        }
        return ans;
    }
};