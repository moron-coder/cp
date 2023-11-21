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
    int sumCounts(vector<int>& ar) {
        int n=ar.size(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=i;j<n;j++){
                mp[ar[j]]++;
                int sz = mp.size();
                ans+=(sz*sz);
            }
        }
        return ans;
    }
};