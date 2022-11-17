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
    int minimumRounds(vector<int>& ar) {
        unordered_map<int,int> mp;
        for(auto it:ar) mp[it]++;
        int ans=0;
        for(auto it:mp){
            if(it.second==1) return -1;
            while (it.second%3){
                it.second-=2,ans++;
            }
            ans+=(it.second)/3;
        }
        return ans;
    }
};