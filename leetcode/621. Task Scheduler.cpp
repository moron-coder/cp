#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>

// pre-emptive scheduling

class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        priority_queue<int> pq;     //  fq, char
        int *fq = new int[26]();
        for(auto it:tasks) fq[it-'A']++;
        for(int i=0;i<26;i++) if(fq[i]) pq.push({fq[i]});
        int time=0;
        while (pq.size()){
            int currentPeriodTime=0;
            queue<int> nextTasks;
            for(int i=0;i<=k;i++){
                if(pq.empty()){
                    if(nextTasks.empty()) return time+currentPeriodTime;
                    break;
                }
                int cur=pq.top();
                pq.pop();
                currentPeriodTime++; //  'cur' will run at 'time'
                cur--;
                if(cur) nextTasks.push(cur);
            }
            while (nextTasks.size()){
                pq.push(nextTasks.front());
                nextTasks.pop();
            }
            time+=k+1;      //  one cycle ends
        }
        return time;
    }
};