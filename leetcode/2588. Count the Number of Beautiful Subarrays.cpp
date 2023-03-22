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
    long long beautifulSubarrays(vector<int>& ar) {
        long long pXors=0,ans=0;
        unordered_map<long long,long long> fq;
        for(auto it:ar){
            pXors^=it;
            if(pXors==0) ans++;
            ans+=fq[pXors];
            fq[pXors]++;
        }
        return ans;
    }
};