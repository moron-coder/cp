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
    int dp[100001];

    int getSum(int n){
        cout<<"n= "<<n<<endl;
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return i+getSum(n/i);
        }
        return dp[n]=n;
    }

    int smallestValue(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=n;
        while (1){
            int sm=getSum(ans);
            cout<<"sm= "<<sm<<endl;
            if(sm==ans) break;
            ans=sm;
        }
        return ans;
    }
};