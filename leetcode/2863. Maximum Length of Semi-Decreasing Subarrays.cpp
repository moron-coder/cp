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
    int maxSubarrayLength(vector<int>& ar) {
        int n=ar.size(),minIdx=n+1,ans=0,j=0;
        vector<pii> v;
        for(int i=0;i<ar.size();i++) v.push_back({ar[i],i});
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i=0;i<n;i++){
            while (v[j].first!=v[i].first){
                minIdx=min(minIdx, v[j].second);
                j++;
            }
            ans=max(ans,v[i].second-minIdx+1);
        }
        return ans;
    }
};