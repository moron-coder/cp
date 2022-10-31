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
    long long ctOps(vector<int> &ar,vector<int> &tg){
        long long incr=0;
        for(long long i=0;i<ar.size();i++) incr+=abs(ar[i]-tg[i])/2;
        return incr;
    }

    long long makeSimilar(vector<int>& ar, vector<int>& tg) {
        vector<int> arO,arE,tgO,tgE;
        for(auto it:ar){
            if(it%2) arO.push_back(it);
            else arE.push_back(it);
        }
        for(auto it:tg){
            if(it%2) tgO.push_back(it);
            else tgE.push_back(it);
        }
        sort(arO.begin(),arO.end());
        sort(arE.begin(),arE.end());
        sort(tgO.begin(),tgO.end());
        sort(tgE.begin(),tgE.end());
        return (ctOps(arO,tgO)+ctOps(arE,tgE))/2;
    }
};