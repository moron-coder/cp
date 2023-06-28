#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& ar, vector<int>& cost) {
        long long n=ar.size(),sum=0,sumCum=0,ans=LONG_MAX,pSum=0,pSumCum=0;
        vector<pair<int,int>> v;
        for(int i=0;i<ar.size();i++){
            v.push_back({ar[i],cost[i]});
            sum+=cost[i];
            sumCum+=1LL*ar[i]*cost[i];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            ans = min(ans,v[i].first*(2*pSum-sum)+sumCum-2*pSumCum);
            pSum+=v[i].second;
            pSumCum+=1LL*v[i].first*v[i].second;
        }
        return ans;
    }
};