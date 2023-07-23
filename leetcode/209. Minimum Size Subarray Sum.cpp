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
    int minSubArrayLen(int k, vector<int>& ar) {
        int n=ar.size(),lo=1,hi=n,ans=n+1;
        while (lo<=hi){
            int mid = lo+(hi-lo)/2,sum=0;
            for(int i=0;i<n;i++){
                sum+=ar[i];
                if(i>=mid) sum-=ar[i-mid];
                if(sum>=k) break;
            }
            if(sum>=k){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans==n+1?0:ans;
    }
};