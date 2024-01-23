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
#define ll long long int
#define mod 1000000007

int findWays(vector<int>& ar, int k){
    int n=ar.size();
    int **dp=new int*[n];
    for(int i=0;i<n;i++) dp[i]=new int[k+1]();
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            int incAns=0;
            if(ar[i]<=j){
                if(i) incAns=dp[i-1][j-ar[i]];
                else incAns=(ar[i]==j);
            }
            int notIncAns=(i)?dp[i-1][j]:(j==0);
            dp[i][j]=(incAns+notIncAns)%mod;
        }
    }
    return dp[n-1][k];
}
