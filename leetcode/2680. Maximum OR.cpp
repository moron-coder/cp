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
    long long maximumOr(vector<int>& ar, int k) {
        int n=ar.size();
        if(n<=1) return ar[0]<<k;
        vector<int> suf(n,ar.back());
        for(int i=n-2;i>=0;i--){
            suf[i]=ar[i]|suf[i+1];
        }
        long long ans = max((1LL*suf[0]),((1LL*ar[0])<<k)|suf[1]);
        cout<<(((1LL*ar[0])<<k)|suf[1])<<" is probable ans\n";
        for(int i=1;i<n-1;i++){
            ans=max(ans,(ar[i-1]|((1LL*ar[i])<<k)|suf[i+1]));
            ar[i]=(ar[i-1]|ar[i]);
        }
        ans=max(ans,ar[n-2]|((1LL*ar.back())<<k));
        return ans;
    }
};