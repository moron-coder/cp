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
    int minimumSum(vector<int>& ar) {
        int n=ar.size(),ans=-1;
        vector<int> pre(n,ar[0]),suf(n,ar.back());
        for(int i=1;i<n;i++) pre[i]=min(ar[i],pre[i-1]),suf[n-1-i]=min(ar[n-1-i],suf[n-i]);
        for(int i=1;i+1<n;i++) if(pre[i-1]<ar[i] && suf[i+1]<ar[i] && 
        (ans==-1 || ans>pre[i-1]+ar[i]+suf[i+1])){
            ans = pre[i-1]+ar[i]+suf[i+1];
        }
        return ans;
    }
};