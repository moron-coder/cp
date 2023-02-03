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

int minRemovals(vector<int>& ar, int n, int k){
    sort(ar.begin(),ar.end());
    int ans=n;
    for(int i=0;i<n;i++){
        int nxt=upper_bound(ar.begin(),ar.end(),ar[i]+k)-ar.begin();
        ans=min(ans,i+n-nxt);
    }
    return ans;
}
