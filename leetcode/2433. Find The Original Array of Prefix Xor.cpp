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
    vector<int> findArray(vector<int>& ar) {
        vector<int> ans(ar.size(),ar[0]);
        for(int i=1,cur=ar[0];i<ar.size();i++) ans[i]=(cur^ar[i]),cur=(cur^ar[i]);
        return ans;
    }
};