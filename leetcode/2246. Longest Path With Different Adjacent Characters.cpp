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
    int dp[100001];

    int makeLongest(vector<vector<int>> &edges,int pos,string &s){
        if(dp[pos]!=-1) return dp[pos];
        int curAns=1;
        for(auto it:edges[pos]) {
            if(s[it]!=s[pos]) {
                curAns=max(curAns,1+makeLongest(edges,it,s));
            }
            makeLongest(edges, it,s);
        }
        return dp[pos]=curAns;
    }

    int ans;

    void move(vector<vector<int>> &edges,int pos,string &s){
        int m1=0,m2=0;              //  max and 2nd max children subtree length from "pos"
        for(auto it:edges[pos]){
            if(s[it]!=s[pos]){
                int subLen=dp[it];
                if(subLen>m1){
                    m2=m1;
                    m1=subLen;
                }else if(subLen>m2) m2=subLen;
                ans=max(ans,1+m1+m2);
            }
            move(edges,it,s);
        }
    }

    int longestPath(vector<int>& parent, string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        ans=1;
        vector<vector<int>> edges(n,vector<int>());
        for(int i=1;i<n;i++) edges[parent[i]].push_back(i);
        makeLongest(edges,0,s);
        move(edges,0,s);
        return ans;
    }
};