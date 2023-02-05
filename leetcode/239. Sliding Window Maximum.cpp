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
    vector<int> maxSlidingWindow(vector<int>& ar, int k) {
        // we want to maintain a given order => monotonic stack
        // we want to handle the above problem for a given range
        int n=ar.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++){
            while (dq.size() && ar[dq.back()]<ar[i]){
                dq.pop_back();
            }
            while (dq.size() && dq.front()<=i-k) dq.pop_front();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(ar[dq.front()]);
        }
        return ans;
    }
};