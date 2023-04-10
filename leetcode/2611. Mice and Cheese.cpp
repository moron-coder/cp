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
    int miceAndCheese(vector<int>& ar1, vector<int>& ar2, int k) {
        int ans=0;
        for(auto it:ar2) ans+=it;
        vector<int> difs;
        for(int i=0;i<ar1.size();i++) difs.push_back(ar1[i]-ar2[i]);
        sort(difs.begin(),difs.end());
        while (k--){
            ans+=difs.back();
            difs.pop_back();
        }
        return ans;
    }
};