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
    vector<int> findBuildings(vector<int>& ar) {
        vector<int> stk;
        int n=ar.size();
        for(int i=0;i<n;i++){
            while (stk.size() && ar[stk.back()]<=ar[i]) stk.pop_back();
            stk.push_back(i);
        }
        return stk;
    }
};