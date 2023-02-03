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
    void p1(vector<int> &ar,vector<long long> &gEq){
        long long n=ar.size();
        stack<long long> stk;
        for(long long i=n-1;i>=0;i--){
            while (stk.size() && ar[stk.top()]<ar[i]) stk.pop();
            if(stk.size()) gEq[i]=stk.top();
            stk.push(i);
        }
    }

    void p2(vector<int> &ar,vector<long long> &lt){
        long long n=ar.size();
        stack<long long> stk;
        for(long long i=n-1;i>=0;i--){
            while (stk.size() && ar[stk.top()]>=ar[i]) stk.pop();
            if(stk.size()) lt[i]=stk.top();
            stk.push(i);
        }
    }

    long long minCost(vector<int>& ar, vector<int>& costs) {
        long n=ar.size();
        // for every index, find the index which is (greater than or equal to) and the index which is (less than) the current index
        vector<long long> gEq(n,-1),lt(n,-1);
        p1(ar,gEq);
        p2(ar,lt);
        long long *dp=new long long[n]();
        dp[n-1]=costs[n-1];
        for(long long i=n-2;i>=0;i--){
            dp[i]=LONG_MAX;
            if(lt[i]!=-1) dp[i]=min(dp[i],costs[i]+dp[lt[i]]);
            if(gEq[i]!=-1) dp[i]=min(dp[i],costs[i]+dp[gEq[i]]);
        }
        return dp[0]-costs[0];
    }
};