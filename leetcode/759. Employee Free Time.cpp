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
        map<int,int> mp;
        for(vector<Interval> empSchedule:schedule){
            for(Interval it:empSchedule){
                mp[it.start]++;
                mp[it.end]--;
            }
        }
        bool isFree=true;
        int startTime=INT_MIN,sum=0;

        vector<Interval> ans;

        for(auto it:mp){
            sum+=it.second;

            if(isFree && sum>0){
                //  push this interval [startTime, it.first]
                isFree=false;
                if(startTime!=INT_MIN) {
                    ans.push_back(Interval(startTime,it.first));
                }
            }else if(sum==0){
                isFree=true;
                startTime=it.first;
            }
        }
        return ans;
    }
};