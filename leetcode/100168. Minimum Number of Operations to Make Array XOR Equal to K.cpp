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
    int ct(int x){
        int ans=0;
        while (x){
            if(x&1) ans++;
            x=(x>>1);
        }
        return ans;
    }

    int minOperations(vector<int>& ar, int k) {
        int tmp=k;
        for(auto it:ar){
            tmp=tmp^it;
        }
        return ct(tmp);
    }
};