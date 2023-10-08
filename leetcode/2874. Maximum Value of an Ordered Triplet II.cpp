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
    long long maximumTripletValue(vector<int>& ar) {
        vector<int> pre = ar, suf = ar;
        for(int i=1;i<ar.size();i++){
            pre[i] = max(pre[i],pre[i-1]);
        }

        for(int i=ar.size()-2;i>=0;i--){
            suf[i] = max(suf[i],suf[i+1]);
        }

        long long ans=0;

        for(int i=1;i<ar.size()-1;i++){
            ans = max(ans,1LL*(pre[i-1]-ar[i])*suf[i+1]);
        }

        return ans;

    }
};