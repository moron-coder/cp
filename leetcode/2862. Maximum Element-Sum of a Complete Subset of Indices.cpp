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
    long long maximumSum(vector<int>& ar) {
        long long n=ar.size(),ans=0;
        for(long long i=1;i<=n;i++){
            ans=max(ans,(long long)ar[i-1]);
            long long cur=0;
            for(long long j=1;j*j*i<=n;j++){
                cur+=(ar[i*j*j-1]);
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};
