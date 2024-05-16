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
    int maxSumMinProduct(vector<int>& ar) {
        long long int n=ar.size();
        vector<int> leftSmaller(n,-1),rightSmaller(n,-1);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while (stk.size() && ar[stk.top()]>ar[i]){
                leftSmaller[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        while (stk.size()){
            stk.pop();
        }
        for(int i=0;i<n;i++){
            while (stk.size() && ar[stk.top()]>ar[i]){
                rightSmaller[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        vector<int> pre(n,ar[0]);
        long long ans=0;
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+ar[i];
        for(int i=0;i<n;i++){
            int i2 = rightSmaller[i],s2=pre.back();
            if(i2!=-1){
                s2 = pre[i2-1];
            }
            int i1 = leftSmaller[i],s1=0;
            if(i1!=-1){
                s1 = pre[i1];
            }
            ans = max(ans,1LL*ar[i]*(s2-s1));
        }
        return ans%mod;
    }
};