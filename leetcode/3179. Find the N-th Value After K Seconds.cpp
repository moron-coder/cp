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
    int valueAfterKSeconds(int n, int k) {
        vector<int> ar(n,1);
        for(int i=0;i<=k;i++){
            for(int j=1;j<n;j++){
                ar[j]+=ar[j-1];
            }
        }
        return ar.back();
    }
};