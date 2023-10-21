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
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        reverse(tasks.begin(),tasks.end());
        int n=tasks.size(),ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:processorTime) pq.push(it);
        for(int i=0;i<tasks.size();i+=4){
            int tp = pq.top();
            pq.pop();
            int nextAv = tp+tasks[i];
            nextAv = tp+max({tasks[i],tasks[i+1],tasks[i+2],tasks[i+3]}); 
            ans=max(ans,nextAv);
        }
        return ans;
    }
};