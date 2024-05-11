#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pll pair<ll,ll> 

class Solution {
    void execTasks(ll &timer, vector<int> &ans, priority_queue<pll,vector<pll>,greater<pll>> &pq){
        if (pq.size()){
            pll tmp = pq.top();
            pq.pop();
            timer+=tmp.first;
            ans.push_back(tmp.second);
        }
    }

    void populateTasks(ll &timer, priority_queue<pll,vector<pll>,greater<pll>> &q, priority_queue<pll,vector<pll>,greater<pll>> &pq,unordered_map<ll,ll> &mp){
        if (q.size() && q.top().first<=timer){
            pll curTask = q.top();
            q.pop();
            pq.push({mp[curTask.second], curTask.second});
        }
    }

public:
    vector<int> getOrder(vector<vector<int>>& ar) {
        ll n=ar.size();
        priority_queue<pll,vector<pll>,greater<pll>> pq;         //  processing_time, task_id
        ll timer=0;
        vector<int> ans;
        priority_queue<pll,vector<pll>,greater<pll>> q;                   //  {enqueue_time, task_id}
        unordered_map<ll,ll> mp;      //  {task_id, processing_time}

        for(int i=0;i<n;i++){
            q.push({ar[i][0],i});
            mp[i] = ar[i][1];
        }
        
        while (q.size()){
            while (pq.size() && timer<q.top().first){
                execTasks(timer,ans,pq);
            }

            timer = max(timer, q.top().first);

            while (q.size() && q.top().first<=timer){
                populateTasks(timer,q,pq,mp);
            }

            execTasks(timer,ans,pq);
        }
        while (pq.size()){
            execTasks(timer,ans,pq);
        }
        return ans;
    }
};