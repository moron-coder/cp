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
    int minSwaps(vector<int>& ar) {
        int n=ar.size(),oneCt=0,cur=0,ans=INT_MAX;
        for(auto it:ar) oneCt+=it;
        for(int i=0;i<n;i++){
            if(ar[i]) cur++;
            if(i-oneCt>=0 && ar[i-oneCt]) cur--;
            if(i>=oneCt-1) ans=min(ans,oneCt-cur);
        }
        return ans;
    }
};