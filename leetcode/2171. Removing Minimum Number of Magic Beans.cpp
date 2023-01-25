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
    long long minimumRemoval(vector<int>& ar) {
        sort(ar.begin(),ar.end());
        ll n=ar.size(),ans=ar.back(),mx=max(ar.back(),ar[0]),mn=min(ar.back(),ar[0]);
        vector<ll> suf(n,ar.back()),pre(n,ar[0]);
        for(ll i=n-2;i>=0;i--) suf[i]=ar[i]+suf[i+1],ans+=ar[i],mn=min(mn,(ll)ar[i]),mx=max(mx,(ll)ar[i]);
        for(ll i=1;i<n;i++) pre[i]=ar[i]+pre[i-1];
        for(ll i=1;i<n;i++){
            if(ar[i]!=ar[i-1]){
                ll cur1=pre[i-1];
                ll cur2=suf[i];
                ll eq=ar[i]*(n-i);
                ll cur=cur1+(cur2-eq);
                ans=min(ans,cur);
            }
        }
        if(mn==mx) return 0;
        return ans;
    }
};