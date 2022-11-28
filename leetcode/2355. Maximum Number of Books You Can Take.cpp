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
    long long maximumBooks(vector<int> &ar) {
        long long n = ar.size(), ans = ar[0];
        vector<long long> seqBreaker(n, -1);
        vector<long long> idx(1, n - 1);  //  low->high mono stack
        for (long long i = n - 2; i >= 0; i--) {
            // for index i, I have to store index j (i<j) such that ar[i]<ar[j]-(j-i)
            while (idx.size() && ar[idx.back()] > ar[i]+(idx.back()-i)) {
                seqBreaker[idx.back()] = i;
                idx.pop_back();
            }
            idx.push_back(i);
        }
        for(auto it:seqBreaker) cout<<it<<" ";
        cout<<endl;
        long long *dp = new long long[n]();
        dp[0] = ar[0];
        for (long long i = 1; i < n; i++) {
            if (seqBreaker[i] == -1) {
                if(ar[i]<=i+1) dp[i]=(1LL*ar[i]*(ar[i]+1))/2;
                else dp[i]= ((2LL*ar[i]-i)*(i+1))/2;
                ans=max(ans,dp[i]);
                continue;
            }
            long long dif=i-seqBreaker[i];
            dp[i]=(1LL*ar[i]*(ar[i]+1)-(1LL*ar[i]-dif)*(ar[i]-dif+1))/2+dp[seqBreaker[i]];
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};