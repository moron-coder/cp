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
    int trap(vector<int>& ar) {
        int n=ar.size(),ans=0;
        vector<int> pre(n,ar[0]), suf(n,ar[n-1]);
        for(int i=n-2;i>0;i--){
            suf[i]=max(ar[i],suf[i+1]);
        }
        for(int i=1;i<n-1;i++){
            pre[i]=max(ar[i],pre[i-1]);
            ans+=min(pre[i],suf[i])-ar[i];
        }
        return ans;
    }
};