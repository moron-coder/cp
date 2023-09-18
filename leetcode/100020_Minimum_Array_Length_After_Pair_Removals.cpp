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
    int minLengthAfterRemovals(vector<int>& ar) {
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        for(auto it:ar) mp[it]++;
        for(auto it:mp){
            pq.push(it.second);
        }
        while (pq.size()>1){
            int tp = pq.top();
            pq.pop();
            if(pq.empty()) break;
            int tp2 = pq.top();
            pq.pop();
            tp--;
            tp2--;
            if(tp) pq.push(tp);
            if(tp2) pq.push(tp2);
        }
        return pq.size()?pq.top():0;
    }
};