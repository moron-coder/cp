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
    int maxProfit(vector<int>& ar) {
        int ans=0,n=ar.size();
        int *sufMaxProfit = new int[n](),*preMin=new int[n](),*sufMax=new int[n]();
        sufMax[n-1]=ar.back();
        preMin[0]=ar[0];
        for(int i=1;i<n;i++) preMin[i]=min(preMin[i-1],ar[i]);
        for(int i=n-2;i>=0;i--) sufMax[i]=max(ar[i],sufMax[i+1]);
        for(int i=n-2;i>=0;i--) sufMaxProfit[i]=max(sufMaxProfit[i+1],sufMax[i+1]-ar[i]);
        for(int i=1;i<n;i++){
            ans=max({ans,ar[i]-preMin[i-1]+(i+1<n?sufMaxProfit[i+1]:0)});
        }
        return ans;
    }
};