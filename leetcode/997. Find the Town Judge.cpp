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
    int findJudge(int n, vector<vector<int>>& ar) {
        pii *t=new pii[n];
        for(int i=0;i<n;i++) t[i].first=0,t[i].second=0;
        for(auto it:ar){
            t[it[1]-1].second++;
            t[it[0]-1].first++;
        }
        for(int i=0;i<n;i++){
            if(t[i].first==0 && t[i].second==n-1) return i+1;
        }
        return -1;
    }
};