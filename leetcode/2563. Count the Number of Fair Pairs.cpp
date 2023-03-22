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
        long long countFairPairs(vector<int>& ar, int lower, int upper) {
        long long ans=0;
        sort(ar.begin(),ar.end());
        for(int n=ar.size(),i=0;i<n;i++){
            int p1 = lower_bound(ar.begin(),ar.end(),lower-ar[i])-ar.begin();
            p1=max(p1,i+1);
            int p2 = upper_bound(ar.begin(),ar.end(),upper-ar[i])-ar.begin()-1;
            if(p2<=i) continue;
            ans+=p2-p1+1;
        }
        return ans;
    }
};