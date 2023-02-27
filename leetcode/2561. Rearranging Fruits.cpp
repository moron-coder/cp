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
    long long minCost(vector<int>& A, vector<int>& B) {
        map<int, int> count;
        for (int a : A)
            ++count[a];
        for (int a : B)
            --count[a];
        //debug
        for(auto it:count){
            cout<<it.first<<" -- "<<it.second<<endl;
        }
        //debug
        vector<long long> swaps;
        long long res = 0, small = begin(count)->first;
        for (auto [a, v] : count) {
            if (v % 2) return -1;
            for (int i = 0; i < abs(v) / 2; ++i)
                swaps.push_back(a);
        }
        //debug
        for(auto it:swaps) cout<<it<<" ";
        cout<<endl;
        //debug
        for (int i = 0; i < swaps.size() / 2; ++i)
            res += min(swaps[i], small * 2);
        return res;
    }
};