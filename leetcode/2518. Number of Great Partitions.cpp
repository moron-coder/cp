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
    ll dp[1001][1001];

    ll help(vector<int>& ar, ll pos, ll k) {
        ll n = ar.size();
        if (pos >= n){
            if(k){
                return 1;     //  if (k>0) return 1;
            }
            return 0;
        }
        if (dp[pos][k] != -1) return dp[pos][k];
        ll small = help(ar, pos + 1, k);
        if (k - ar[pos] > 0) small = (small + help(ar, pos + 1, k - ar[pos])+mod) % mod;
        return dp[pos][k]=small;
    }

    int countPartitions(vector<int>& ar, int k) {
        ll tmp=0;
        for(auto it:ar) tmp+=it;
        memset(dp, -1, sizeof(dp));
        int small = help(ar, 0, k), n = ar.size();
        if(tmp<2*k) return 0;
        vector<ll> powers(1001, 1);
        for (ll i = 1; i <= 1000; i++) powers[i] = ((powers[i - 1] << 1)+mod) % mod;
        return (powers[n] - small*2-2+mod)%mod;
    }
};