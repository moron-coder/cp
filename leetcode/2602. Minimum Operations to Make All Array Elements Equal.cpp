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
    vector<long long> minOperations(vector<int>& ar, vector<int>& queries) {
        int n=ar.size();
        vector<long long> ret;
        sort(ar.begin(),ar.end());
        vector<long long> preSum(n,ar[0]),sufSum(n,ar.back());
        for(int i=1;i<n;i++) preSum[i]=ar[i]+preSum[i-1];
        for(int i=n-2;i>=0;i--) sufSum[i]=ar[i]+sufSum[i+1];
        for(long long it:queries){
            long long ans=0;
            long long pos=lower_bound(ar.begin(),ar.end(),it)-ar.begin();
            if(pos==n){
                ans=it*n-preSum[n-1];
            }else if(pos==0){
                ans=sufSum[0]-it*n;
            }else{
                ans=sufSum[pos]-n*it-preSum[pos-1]+2*pos*it;
            }
            ret.push_back(ans);
        }
        return ret;
    }
};