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
    vector<int> lastVisitedIntegers(vector<string>& ar) {
        int n=ar.size(),ptr=-1;
        vector<int> v,ans;
        for(auto it:ar){
            if(it=="prev"){
                if(ptr==-1) ans.push_back(-1);
                else{
                    ans.push_back(v[ptr]);
                    ptr=max(-1,ptr-1);
                }
            }else{
                v.push_back(stoi(it));
                ptr=v.size()-1;
            }
        }
        return ans;
    }
};