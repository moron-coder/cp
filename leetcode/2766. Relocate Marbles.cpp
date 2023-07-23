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
    vector<int> relocateMarbles(vector<int>& ar, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> mp;
        for(int i=0;i<ar.size();i++){
            mp[ar[i]]++;
        }
        for(int i=0;i<moveFrom.size();i++){
            if(mp.count(moveFrom[i])){
                mp.erase(moveFrom[i]);
                mp[moveTo[i]]=1;
            }
        }
        vector<int> ans;
        for(auto it:mp) ans.push_back(it.first);
        return ans;
    }
};