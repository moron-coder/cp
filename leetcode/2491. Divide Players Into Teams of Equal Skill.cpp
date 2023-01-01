#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pbi pair<bool, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int

class Solution {
public:
    long long dividePlayers(vector<int>& ar) {
        ll sm=0,n=ar.size(),unitSum=-1,ans=0;
        unordered_map<int,vector<int>> mp;  //  num->indexes
        for(int i=0;i<n;i++){
            sm+=ar[i];
            mp[ar[i]].push_back(i);
        }
        unitSum=sm/(n/2);
        for(int i=0;i<n;i++){
            while(mp[ar[i]].size()){
                int n2=unitSum-ar[i];
                if(!mp.count(n2) || !mp[n2].size()) return -1;
                ans=(ans+ar[mp[n2].back()]*ar[mp[ar[i]].back()]);
                mp[n2].pop_back();
                mp[ar[i]].pop_back();
            }
        }
        return ans;
    }
};