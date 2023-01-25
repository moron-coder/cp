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
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> ar;
        for(int i=0;i<n;i++) ar.push_back({efficiency[i],speed[i]});
        sort(ar.begin(),ar.end());
        ll sum=0,ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;    //  min pq
        for(int i=n-1;i>=0;i--){
            pq.push(ar[i].second);
            sum=(sum+ar[i].second);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,(sum*ar[i].first));
        }
        return ans%mod;
    }
};