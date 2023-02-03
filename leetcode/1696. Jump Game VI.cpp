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
    int maxResult(vector<int>& ar, int k) {
        int n=ar.size();
        deque<int> dq;
        int *dp=new int[n];
        dp[n-1]=ar[n-1];
        dq.push_back(n-1);
        for(int i=n-2;i>=0;i--){
            while (dq.size() && dq.front()>i+k) dq.pop_front();
            if(dq.empty()){
                // invalid k
                return -1;
            }
            dp[i]=ar[i]+dp[dq.front()];
            while(dq.size() && dp[dq.back()]<=dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[0];
    }
};