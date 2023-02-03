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
    ll help(ll n){
        if(n==0) return 1;
        ll ans=1,sm=help(n/2);
        if(n&1) ans=2;
        ans=(ans%mod*sm%mod)%mod;
        ans=(ans%mod*sm%mod)%mod;
        return (ans+mod)%mod;
    }

    int monkeyMove(int n) {
        // using fast exponentiation, calc. 2^n
        return help(n)-2;
    }
};