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
    int minSizeSubarray(vector<int>& ar, int k) {
        long long curSum=0,i=0,totSum = 0, n=ar.size(), ans=0, extra=INT_MAX;
        for(auto it:ar) totSum+=it;
        for(int i=0;i<n;i++) ar.push_back(ar[i]);
        ans = (k/totSum)*n;
        k%=totSum;
        if(k==0){
            return ans;
        }

        for(int j=0;j<2*n;j++){
            curSum+=ar[j];
            while (curSum>k){
                curSum-=ar[i];
                i++;
            }
            if(curSum==k){
                extra = min(extra,j-i+1);
                curSum-=ar[i];
                i++;
            }
        }
        if(extra==INT_MAX) return -1;
        return ans+extra;
    }
};