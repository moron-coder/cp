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

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pii> v;
        for(auto empSchedules:schedule){
            for(auto itv : empSchedules){
                v.push_back({itv.start,itv.end});
            }
        }
        sort(v.begin(),v.end());
        int mx=v[0].second;
        vector<Interval> ans;
        for(auto it:v){
            if(it.first>mx){
                ans.push_back(Interval(mx,it.first));
            }
            mx=max(mx,it.second);
        }
        return ans;
    }
};