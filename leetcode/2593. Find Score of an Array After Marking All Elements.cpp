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

    long long findScore(vector<int>& ar) {
        long long n=ar.size(),ans=0;
        vector<pii> sAr;
        for(int i=0;i<ar.size();i++) sAr.push_back({ar[i],i});
        sort(sAr.begin(),sAr.end());
        unordered_set<int> used;
        for(auto it:sAr){
            if(used.count(it.second)) continue;
            int idx=it.second,num=it.first;
            used.insert(idx-1);
            used.insert(idx+1);
            used.insert(idx);
            ans+=num;
        }
        return ans;
    }
};