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
    const int MAX_WT = 10000000;
public:
    int networkDelayTime(vector<vector<int>>& ar, int n, int k) {
        vector<int> wt(n,MAX_WT);
        wt[k-1]=0;
        for(int ct=0;ct<n-1;ct++){
            for(int i=0;i<ar.size();i++){
                int u=ar[i][0]-1, v=ar[i][1]-1, w=ar[i][2];
                if(wt[u]!=MAX_WT){
                    wt[v]=min(wt[v], wt[u]+w);
                }
            }
        }
        int ans=0;
        for(auto it:wt){
            ans=max(ans,it);
        }
        return (ans==MAX_WT)?-1:ans;
    }
};