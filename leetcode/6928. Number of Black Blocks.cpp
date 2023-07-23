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
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>>& coordinates) {
        unordered_map<long long,long long> mp;
        for(auto it:coordinates){
            long long i=it[0],j=it[1];
            if(i && j){
                mp[(i-1)*m+(j-1)]++;
            }
            if(i && j+1<m){
                mp[(i-1)*m+j]++;
            }
            if(j && i+1<n){
                mp[i*m+(j-1)]++;
            }
            if(i+1<n && j+1<m){
                mp[i*m+j]++;
            }
        }
        vector<long long> ans(5,0);
        long long colorBlockCt=0;
        for(auto it:mp){
            ans[it.second]++;
            colorBlockCt++;
        }
        ans[0]=(1LL*m*n-m-n+1)-colorBlockCt;
        return ans;
    }
};