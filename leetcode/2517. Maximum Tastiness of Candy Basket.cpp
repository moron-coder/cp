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
    bool ok(vector<int> &ar,int dif,int k){
        int ct=1,nxt=0,n=ar.size();
        while (nxt<n){
            nxt=lower_bound(ar.begin(),ar.end(),ar[nxt]+dif)-ar.begin();
            if(nxt<n) ct++;
        }
        return ct>=k;
    }

    int maximumTastiness(vector<int>& ar, int k) {
        int ans=0,lo=0,hi=1000000001;
        sort(ar.begin(),ar.end());
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(ok(ar,mid,k)){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans;
    }
};