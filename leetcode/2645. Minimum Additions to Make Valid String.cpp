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
    int addMinimum(string ar) {
        int n=ar.size(),abcCt=1;
        for(int i=0;i<n-1;i++){
            if(ar[i+1]<=ar[i]) abcCt++;
        }
        return abcCt*3-n;
    }
};