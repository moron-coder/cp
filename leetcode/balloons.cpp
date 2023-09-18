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
    int maxCoins(vector<int>& ar1) {
        int n=ar1.size();
        vector<int> ar(1,1);
        for(auto it:ar1) ar.push_back(it);
        ar.push_back(1);
        
        int **dp=new int*[n+2];
        for(int i=0;i<=n+1;i++) dp[i]=new int[n+2]();
        
        for(int len=1;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                    int j=i+len-1;
                    for(int t=i;t<=j;t++){
                        int cur=ar[i-1]*ar[j+1]*ar[t];
                        int extra=dp[i][t-1]+dp[t+1][j];
                        dp[i][j]=max(dp[i][j], cur+extra); 
                    }
                
            }
        }
        return dp[1][n];
    }
};