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
    bool find132pattern(vector<int>& ar) {
        int s3Max = INT_MIN,n=ar.size();
        bool ans=false;
        stack<int> stk;
        // s3 is the biggest integer which is smaller than some integer
        for(int i=n-1;i>=0;i--){
            if(s3Max>ar[i]) return true;
            while (stk.size() && ar[i]>stk.top()){
                s3Max=stk.top();
                stk.pop();
            }
            stk.push(ar[i]);
        }
        return false;
    }
};