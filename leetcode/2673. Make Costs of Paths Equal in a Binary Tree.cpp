#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<pair<int, int>> ar;
        for(int i=0;i<n;i++) ar.push_back({0,0});
        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=max(ar[i].first,ar[i].second)-min(ar[i].first,ar[i].second);
            if(i&1){
                ar[i/2].first=cost[i]+max(ar[i].first,ar[i].second);
            }else{
                ar[(i-1)/2].second=cost[i]+max(ar[i].first,ar[i].second);
            }
        }
        return ans;
    }
};