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

/**
* @author : Utkarsh Kumar
* @date : 2024-07-05
*/

class Solution {
public:
    int maximumLength(vector<int>& ar) {
        int n=ar.size(),zrs=0,ons=0,alts0=0,alts1=0,ans=0;
        for(auto it:ar){
            if(it&1){
                ons++;
                alts1 = max(alts1, alts0+1);
            }else{
                zrs++;
                alts0 = max(alts0, alts1+1);
            }
            ans=max({ons,zrs,alts0,alts1});
        }
        return ans;
    }
};