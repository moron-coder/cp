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
    long long maximumSumOfHeights(vector<int>& ar) {
        long long n=ar.size(),ans=0;
        for(int i=0;i<n;i++){
            long long curHt=ar[i],curAns=ar[i];
            for(int j=i-1;j>=0;j--){
                curHt=min(curHt,(long long)ar[j]);
                curAns+=curHt;
            }
            curHt=ar[i];
            for(int j=i+1;j<n;j++){
                curHt=min(curHt,(long long)ar[j]);
                curAns+=curHt;
            }
            ans=max(ans,curAns);
        }
        return ans;
    }
};