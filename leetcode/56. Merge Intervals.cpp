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
    static bool cmp(vector<int> &x, vector<int> &y){
        return x[1]<y[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& ar) {
        int n=ar.size();
        sort(ar.begin(),ar.end(),cmp);
        deque<vector<int>> stk;

        for(auto it:ar){
            int lf=it[0],rt=it[1];
            while (!stk.empty() && stk.back()[1]>=lf){
                lf=min(lf,stk.back()[0]);
                rt=max(rt,stk.back()[1]);
                stk.pop_back();
            }
            stk.push_back({lf,rt});
        }
        vector<vector<int>> ans;
        while (stk.size()){
            ans.push_back(stk.front());
            stk.pop_front();
        }
        return ans;
    }
};