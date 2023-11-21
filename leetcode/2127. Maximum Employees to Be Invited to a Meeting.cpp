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
    int help(vector<int> &ar,int pos,int *len){
    }

    int maximumInvitations(vector<int>& ar) {
        int n=ar.size(),ans=-1;
        vector<vector<int>> edges(n,vector<int>());
        int *len = new int[n]();
        for(int i=0;i<n;i++){
            // ans = max(ans,help(ar,i,len)-1);
        }
        return ans;
    }
};