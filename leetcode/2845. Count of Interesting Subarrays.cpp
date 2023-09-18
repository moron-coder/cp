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
    long long countInterestingSubarrays(vector<int>& ar, int m, int k) {
        unordered_map<int,int> mp;
        long long ans=0,curModCt=0;
        for(int i=0;i<ar.size();i++){
            int curAns = 0;
            if(ar[i]%m==k) curModCt=(curModCt+1)%m;
            if(curModCt%m==k){
                curAns++;
                curAns += mp[k];
            }else{
                curAns += mp[(curModCt-k+m)%m];
            }
            ans=(ans+curAns);
            mp[curModCt]++;
        }
        return ans;
    }
};