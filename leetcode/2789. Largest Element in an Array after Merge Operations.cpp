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
    long long maxArrayValue(vector<int>& ar) {
        long long n=ar.size(),ans=ar[0],suf=ar[n-1];
        for(int i=n-2;i>=0;i--){
            if(suf>=ar[i]){
                suf+=ar[i];
            }else{
                suf=ar[i];
            }
            ans=max(ans,suf);
        }
        return ans;
    }
};