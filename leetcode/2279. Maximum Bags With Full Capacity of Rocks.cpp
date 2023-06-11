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
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        //  greedily fill tje additionalRocks
        vector<int> v;
        int ans=0;
        for(int i=0;i<capacity.size();i++) v.push_back(capacity[i]-rocks[i]);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size() && v[i]<=additionalRocks;i++){
            additionalRocks-=v[i];
            ans++;
        }
        return ans;
    }
};