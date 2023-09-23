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
    int countBits(int n){
        int ans=0;
        while (n){
            if(n&1) ans++;
            n=(n>>1);
        }
        return ans;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& ar, int k) {
        int ans=0;
        for(int i=0;i<ar.size();i++){
            if(countBits(i)==k) ans+=ar[i];
        }
        return ans;
    }
};