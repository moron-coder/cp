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
    long long countAlternatingSubarrays(vector<int>& ar) {
        long long n=ar.size(),ans=1;
        long long prev=1,cur=0;
        for(int i=1;i<n;i++){
            cur=(ar[i]==ar[i-1])?1:prev+1;
            ans+=cur;
            prev=cur;
        }
        return ans;   
    }
};