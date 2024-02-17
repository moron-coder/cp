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
    int countMatchingSubarrays(vector<int>& ar, vector<int>& pat) {
        int n=ar.size(),ans=0;
        for(int i=0;i+pat.size()<n;i++){
            int j=0;
            for(;j<pat.size();j++){
                int del = max(min(ar[i+j+1]-ar[i+j],1),-1);
                if(del!=pat[j]) break;
            }
            ans+=(j==pat.size());
        }
        return ans;
    }
};