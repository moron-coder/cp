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
    int numberOfGoodPartitions(vector<int>& ar) {
        int n=ar.size();
        unordered_map<int,pii> mp;
        for(int i=0;i<n;i++){
            if(!mp.count(ar[i])){
                mp[ar[i]]={i,i};
            }else{
                mp[ar[i]].second=i;
            }
        }
        vector<pii> intervals;
        for(auto it:mp) intervals.push_back(it.second);
        sort(intervals.begin(),intervals.end());
        queue<pii> q;
        for(auto it:intervals){
            if(q.empty() || q.back().second<it.first){
                q.push(it);
            }else{
                q.back().second=max(q.back().second,it.second);
            }
        }
        vector<pii> comps;
        while (!q.empty()){
            comps.push_back(q.front());
            q.pop();
        }
        vector<ll> pow2(n,1);
        for(int i=1;i<n;i++){
            pow2[i]=(pow2[i-1]<<1)%mod;
        }
        ll ans=1;
        for(int i=0;i<comps.size();i++){
            ll cur = comps[i].first;
            ll prev=(i)?comps[i-1].second:0;
            ll dif=cur-prev;
            ans=(ans*pow2[dif])%mod;
        }
        return ans;
    }
};