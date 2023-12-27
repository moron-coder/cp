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
    int maxSubarrayLength(vector<int>& ar, int k) {
        int n=ar.size(),i=0,ans=0;
        unordered_map<int,int> mp;
        for(int j=0;j<n;j++){
            mp[ar[j]]++;
            while (mp[ar[j]]>k){
                mp[ar[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};