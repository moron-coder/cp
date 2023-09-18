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
    long long maxSum(vector<int>& ar, int m, int k) {
        long long n=ar.size(),ans=0;
        long long *preSum = new long long[n]();
        preSum[0]=ar[0];
        for(int i=1;i<n;i++) preSum[i]=ar[i]+preSum[i-1];
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[ar[i]]++;
            if(i-k+1>=0){
                if(i-k>=0) {
                    mp[ar[i-k]]--;
                    if(mp[ar[i-k]]==0) mp.erase(ar[i-k]);
                }
                if(mp.size()>=m){
                    ans=max(ans,preSum[i]-preSum[i-k+1]+ar[i-k+1]);
                }
            }
        }
        return ans;
    }
};