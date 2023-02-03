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
    long long putMarbles(vector<int>& weights, int k) {
        ll n=weights.size(),ansMax=weights[0]+weights.back(),ansMin=weights[0]+weights.back();
        priority_queue<int> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        for(int i=0;i<n-1;i++){
            pq1.push(weights[i]+weights[i+1]);
            pq2.push(weights[i]+weights[i+1]);
        }
        for(int i=0;i<k-1;i++){
            ll cur1=pq1.top();
            pq1.pop();
            ansMax+=cur1;
            ll cur2=pq2.top();
            pq2.pop();
            ansMin+=cur2;
        }
        return ansMax-ansMin;
    }
};