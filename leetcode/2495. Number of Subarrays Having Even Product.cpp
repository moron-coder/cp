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
    long long evenProduct(vector<int>& ar){
        ll n=ar.size(),ans=0,idx=n;
        for(int i=n-1;i>=0;i--){
            if(ar[i]%2==0) idx=i;
            ans=(ans+n-idx);
        }
        return ans;
    }
};