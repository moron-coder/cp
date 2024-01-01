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
    long long getMinCost(vector<long long> &pre,vector<int> &ar,int len){
        long long ans=LONG_MAX;
        for(int i=0;i+len-1<ar.size();i++){
            long long midPos=i+(len-1)/2;
            long long sufCost = pre[i+len-1]-pre[midPos]-(i+len-1-midPos+1-1)*ar[midPos];
            long long preCost = 0;
            if(midPos) preCost = pre[midPos-1]-pre[i]+ar[i]-(midPos-1-i+1)*ar[midPos];
            ans=min(ans,sufCost-preCost);
        }
        return ans;
    }

    int maxFrequencyScore(vector<int>& ar, long long k) {
        sort(ar.begin(),ar.end());
        vector<long long> pre;
        long long sum=0;
        for(auto it:ar){
            sum+=it;
            pre.push_back(sum);
        }
        long long n=ar.size(),hi=n,lo=1,ans=1;
        while (lo<=hi){
            long long mid=lo+(hi-lo)/2;
            long long cur=getMinCost(pre,ar,mid);
            if(cur<=k){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};