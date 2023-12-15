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
    int getBestPos(vector<pii> &v,int lo,int hi,int k){
        int ans=-1;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid].first<=k){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }

    vector<int> lexicographicallySmallestArray(vector<int>& ar, int limit) {
        vector<pii> v;
        int n=ar.size();
        vector<int> reach(n,-1);
        for(int i=0;i<ar.size();i++) v.push_back({ar[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            int pos = getBestPos(v,i,n-1,v[i].first+limit);
            if(pos>i){
                reach[i]=pos;
            }else{
                reach[i]=i;
            }
        }

        int curMax=0;
        vector<int> ans(n,-1);
        priority_queue<int,vector<int>,greater<int>> pqVal,pqIdx;
        for(int i=0;i<reach.size();i++){
            curMax=max(curMax,reach[i]);
            pqVal.push(v[i].first);
            pqIdx.push(v[i].second);
            if(curMax==i){
                while (pqVal.size()){
                    ans[pqIdx.top()] = pqVal.top();
                    pqVal.pop();
                    pqIdx.pop();
                }
            }
        }
        while (pqVal.size()){
            ans[pqIdx.top()] = pqVal.top();
            pqVal.pop();
            pqIdx.pop();
        }
        return ans;
    }
};