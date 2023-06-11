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
    int sumDistance(vector<int>& ar, string s, int d) {
        int n=ar.size();
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                ar[i]-=d;
            }else{
                ar[i]+=d;
            }
        }
        sort(ar.begin(),ar.end());
        ll pSum=ar[0],ans=0;
        for(int i=1;i<n;i++){
            ans=(ans+i*ar[i]-pSum+mod)%mod;
            pSum=(pSum+ar[i])%mod;
        }
        return ans;
    }
};