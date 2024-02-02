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
    int minimumCost(vector<int>& ar) {
        int n=ar.size(),ans=ar[0];
        vector<int> tmp;
        for(int i=1;i<ar.size();i++) tmp.push_back(ar[i]);
        sort(tmp.begin(),tmp.end());
        return ans+tmp[0]+tmp[1];
    }
};