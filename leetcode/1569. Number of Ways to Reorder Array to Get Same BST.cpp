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
    int ncr[1001][1001];

    void make(){
        ncr[0][0]=1;
        for(int i=1;i<=1000;i++){
            ncr[i][0]=1;
            for(int j=1;j<=i;j++){
                ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
            }
        }
    }

    int rec(vector<int> &ar){
        if(!ar.size()) return 1;
        vector<int> smalls,bigs;
        for(int i=1;i<ar.size();i++){
            if(ar[i]<ar[0]) smalls.push_back(ar[i]);
            else bigs.push_back(ar[i]);
        }
        int smallSz = smalls.size(), bigSz = bigs.size(), n=ar.size();
        int waysToSelectBlanks = ncr[n-1][smallSz], lf = rec(smalls), rt = rec(bigs);
        ll ans = ((1LL*waysToSelectBlanks*lf)%mod*rt)%mod;
        return ans;
    }

    int numOfWays(vector<int>& ar) {
        int n=ar.size();
        make();
        return rec(ar);
    }
};