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

int findMinDiff(int n, int m, vector<int> ar) {
    sort(ar.begin(),ar.end());
    int ans=ar[m-1]-ar[0];
    for(int i=m;i<n;i++) ans=min(ans,ar[i]-ar[i-m+1]);
    return ans;
}