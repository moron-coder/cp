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
    int minimumDifference(vector<int>& ar, int k) {
        unordered_set<int> prefs;
        int ans=INT_MAX;
        for(auto it:ar){
            unordered_set<int> curs;
            curs.insert(it);
            for(auto it1:prefs){
                ans=min(ans, abs(k-it1&it));
                curs.insert(it1&it);            //  curs has atmost 30 entries
            }
            prefs=curs;
        }
        return ans;
    }
};