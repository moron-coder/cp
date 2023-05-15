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
    int maxMoves(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size(),ans=0;
        int **dp=new int*[n];
        for(int i=0;i<n;i++) dp[i]=new int[m]();
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){
                if(i && ar[i-1][j+1]>ar[i][j]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j+1]+1);
                }
                if(ar[i][j+1]>ar[i][j]){
                    dp[i][j]=max(dp[i][j],1+dp[i][j+1]);
                }
                if(i+1<n && ar[i+1][j+1]>ar[i][j]){
                    dp[i][j]=max(dp[i][j],dp[i+1][j+1]+1);
                }
                if(j==0) ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};