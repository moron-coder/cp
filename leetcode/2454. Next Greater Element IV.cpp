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
    vector<int> secondGreaterElement(vector<int>& ar) {
        int n=ar.size();
        vector<int> v1,ans(n,-1),v2;
        for(int i=0;i<n;i++){
            while (v2.size() && ar[v2.back()]<ar[i]){
                ans[v2.back()]=ar[i];
                v2.pop_back();
            }
            vector<int> tmpVec;
            while (v1.size() && ar[v1.back()]<ar[i]){
                tmpVec.push_back(v1.back());
                v1.pop_back();
            }
            while (tmpVec.size()){
                v2.push_back(tmpVec.back());
                tmpVec.pop_back();
            }
            v1.push_back(i);
        }
        return ans;
    }
};
/*
[40,50,10,20,30]
[40,10,50,20,30]
*/