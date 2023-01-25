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
    bool isOnePresent(string &s){
        for(auto it:s) if(it=='1') return true;
        return false;
    }

    bool makeStringsEqual(string s, string target) {
        if(s==target) return true;
        if(!isOnePresent(s) || !isOnePresent(target)) return false;
        return true;
    }
};