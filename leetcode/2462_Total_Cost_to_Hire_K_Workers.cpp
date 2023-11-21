#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

class Solution {
public:
    long long totalCost(vector<int>& ar, int k, int candidates) {
        int n=ar.size(),i=candidates-1,j=max(i+1,n-candidates);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int it=0;it<candidates;it++){
            pq.push({ar[it],it});
            if(n-1-it>=candidates) pq.push({ar[n-1-it],n-1-it});
        }
        long long ans = 0;
        while (k--){
            pii tp = pq.top();
            pq.pop();
            ans+=tp.first;
            if(tp.second<=i){
                i++;
                if(i<j && i<n) pq.push({ar[i],i});
            }else if(tp.second>=j){
                j--;
                if(j>i) pq.push({ar[j],j});
            }
        }
        return ans;
    }
};