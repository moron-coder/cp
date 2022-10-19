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
    long long countSubarrays(vector<int>& ar, int minK, int maxK) {
        long long i=-1,n=ar.size(),minIdx=-1,maxIdx=-1,ans=0;
        for(int j=0;j<n;j++){
            if(ar[j]<minK || ar[j]>maxK){
                minIdx=-1,maxIdx=-1;
                i=j;
                continue;
            }
            if(ar[j]==minK) minIdx=j;
            if(ar[j]==maxK) maxIdx=j;
            if(minIdx!=-1 && maxIdx!=-1){
                ans=(ans+min(minIdx,maxIdx)-i);
            }
        }
        return ans;
    }
};