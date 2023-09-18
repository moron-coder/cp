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
    int countPairs(vector<vector<int>>& ar, int k) {
        unordered_map<pii,int> mp;
        int ans=0;
        for(auto it:ar){
            int curI = it[0], curJ = it[1];
            for(int i=0;i<=k;i++){
                int prevI = i^curI;
                int prevJ = (k-i)^curJ;
                ans+=mp[{prevI,prevJ}];
            }
            mp[{curI,curJ}]++;
        }
        return ans;
    }
};