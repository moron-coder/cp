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
    long long minCost(vector<int>& ar, int x) {
        ll ans=1000000000001,n=ar.size();
        vector<ll> minPriceOfIdx(n,1000000000001);
        for(int rotationCt=0;rotationCt<n;rotationCt++){
            ll sum=0;
            for(int idx=0;idx<n;idx++){
                minPriceOfIdx[idx]=min((ll)minPriceOfIdx[idx],(ll)ar[(idx-rotationCt+n)%n]);    
                sum+=minPriceOfIdx[idx];           
            }
            ans=min(ans,sum+(1LL*x*rotationCt));
        }
        return ans;
    }
};