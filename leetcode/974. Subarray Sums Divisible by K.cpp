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
    int subarraysDivByK(vector<int>& ar, int k) {
        unordered_map<int,int> mp;
        int ans=0,sum=0;
        for(auto it:ar){
            sum+=it;
            sum=(sum%k+k)%k;
            if(sum==0) ans++;
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};