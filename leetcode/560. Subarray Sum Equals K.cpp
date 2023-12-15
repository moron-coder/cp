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
    int subarraySum(vector<int>& ar, int k) {
        int sum=0,ans=0,n=ar.size();
        unordered_map<int,int> mp;  //  prefix sums to its frequency
        mp[0]=1;
        for(auto it:ar){
            sum+=it;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};