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
    int minimumSum(int n, int k) {
        int len=0,ans=0;
        int *dp = new int[51]();
        for(int i=1;len<n;i++){
            if(i>50 || !dp[i]){
                ans+=i,++len;
                if(k-i>0) dp[k-i]=true;
            }
        }
        return ans;
    }
};