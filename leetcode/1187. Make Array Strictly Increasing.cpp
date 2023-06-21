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
    int dp[2001][2001][2];
    const static int MAX_ANS = 2002;

    int rec(vector<int> &ar1,vector<int> &ar2,int i,int j,bool swappedLastVal){
        //  1) -> in memoization, change only those parameters in recusion calls which can be changed
        // changing an array doesn't make sense as we can't keep track of it.
        int n=ar1.size();
        if(i>=n) return 0;
        if(dp[i][j][swappedLastVal]!=-1) return dp[i][j][swappedLastVal];
        int lastVal = i?ar1[i-1]:INT_MIN;
        if(swappedLastVal){
            lastVal = ar2[j];
        }
        int ansSwap = MAX_ANS, ansNotSwap = MAX_ANS;
        int newJ = upper_bound(ar2.begin()+j,ar2.end(),lastVal)-ar2.begin();
        if(newJ<ar2.size()){
            ansSwap = 1+rec(ar1,ar2,i+1,newJ,true);
        }
        if(ar1[i]>lastVal){
            ansNotSwap = rec(ar1,ar2,i+1,newJ,false);
        }
        return dp[i][j][swappedLastVal] = min(ansSwap,ansNotSwap);
    }

    int makeArrayIncreasing(vector<int>& ar1, vector<int>& ar2) {
        memset(dp,-1,sizeof(dp));
        sort(ar2.begin(),ar2.end());
        int ans = rec(ar1,ar2,0,0,false);
        if(ans>=MAX_ANS) return -1;
        return ans;
    }
};