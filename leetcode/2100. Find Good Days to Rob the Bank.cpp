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
    vector<int> goodDaysToRobBank(vector<int>& ar, int t) {
        // there'll be 2 arrays:
        //  1st: stores how many elements before the current element are non-increasing
        //  2nd: stores how many elements after the current element are non-decreasing
        int n=ar.size();
        vector<int> befs(n,0),afts(n,0),ans;
        for(int i=1;i<n;i++) if(ar[i]<=ar[i-1]) befs[i]=befs[i-1]+1;
        for(int i=n-2;i>=0;i--) if(ar[i]<=ar[i-1]) afts[i]=afts[i+1]+1;
        for(int i=0;i<n;i++) if(befs[i]>=t && afts[i]>=t) ans.push_back(i);
        return ans;
    }
};