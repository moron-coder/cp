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

    int maxJump(vector<int>& ar) {
        int ans=-1,n=ar.size();
        for(int i=2;i<n;i+=2){
            ans=max(ans,ar[i]-ar[i-2]);
        }
        for(int i=3;i<n;i+=2){
            ans=max(ans,ar[i]-ar[i-2]);
        }
        return ans;
    }
};