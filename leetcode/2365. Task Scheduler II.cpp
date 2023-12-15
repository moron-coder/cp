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
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int time=0;
        unordered_map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            if(!mp.count(tasks[i]) || time-mp[tasks[i]]>=space+1){
                mp[tasks[i]]=time;
            }else{
                time=mp[tasks[i]]+space+1;
                mp[tasks[i]]+=space+1;
            }
            time++;
        }
        return time;
    }
};