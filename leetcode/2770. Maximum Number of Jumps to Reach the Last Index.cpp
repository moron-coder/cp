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
    int maximumJumps(vector<int>& ar, int k) {
        int n=ar.size();
        int *dp=new int[n]();
        dp[0]=0;
        for(int i=1;i<n;i++){
            dp[i]=-1;
            for(int j=i-1;j>=0;j--){
                if(abs(ar[i]-ar[j])<=k){
                    if(dp[j]!=-1){
                        dp[i]=max(dp[i],1+dp[j]);
                    }
                }
            }
        }
        return dp[n-1];
    }
};