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
    int totalStrength(vector<int>& ar) {
        ll n=(ll)ar.size(),ans=0;
        stack<ll> stk;
        vector<ll> leftSmall(n,-1),rightSmall(n,n),ps(n,ar[0]),pps(n,ar[0]);
        for(ll i=0;i<n;i++){
            if(i){
                ps[i]=ps[i-1]+ar[i];
                pps[i]=pps[i-1]+ps[i];
            }
            while (stk.size() && ar[stk.top()]>=ar[i]){
                rightSmall[stk.top()]=i;
                stk.pop();
            }
            if(stk.size()) leftSmall[i]=stk.top();
            stk.push(i);
        }  
        for(ll i=0;i<n;i++){
            ll inc = (((pps[rightSmall[i]-1]-pps[i]+ps[i])%mod*(i-leftSmall[i])%mod) -
                      ((pps[i]-pps[leftSmall[i]+1]+ps[leftSmall[i]+1])%mod*(rightSmall[i]-i)%mod) +
                      ((ps[i]-ps[leftSmall[i]+1]+ar[leftSmall[i]+1])%mod*(rightSmall[i]-i)%mod));
            ans=(ans+inc%mod*ar[i]%mod+mod)%mod;
        }
        return ans;
    }
};