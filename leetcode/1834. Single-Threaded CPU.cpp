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

class dt{
    public:
    ll enqTime, prcTime, idx;

    dt(ll enqTime, ll prcTime, ll idx){
        this->enqTime = enqTime;
        this->prcTime = prcTime;
        this->idx = idx;
    }
};

class Solution {
public:
    static bool cmp(dt &x,dt &y){
        if(x.enqTime==y.enqTime){
            return x.idx<y.idx;
        }
        return x.enqTime<y.enqTime;
    }

    void fillCurrentTasks(ll &ptr, ll &clk,vector<dt> &v, priority_queue<pii,vector<pii>,greater<pii>> &pq){
        while (ptr<v.size() && v[ptr].enqTime<=clk){
            pq.push({v[ptr].prcTime, v[ptr].idx});
            ptr++;
        }
    }

    int processTask(ll &clk,priority_queue<pii,vector<pii>,greater<pii>> &pq){
        if(pq.empty()){
            cout<<"empty tasks\n";
            return -1;
        }
        pii cur = pq.top();
        pq.pop();
        clk+=cur.first;
        return cur.second;
    }

    vector<int> getOrder(vector<vector<int>>& ar) {
        vector<dt> v;
        int n=ar.size();
        for(int i=0;i<n;i++){
            dt tmp(ar[i][0],ar[i][1],i);
            v.push_back(tmp);
        }   
        vector<int> ans;
        sort(v.begin(),v.end(),cmp);
        ll clk=0,ptr=0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;         //  {prcTime, idx}
        while (ptr<v.size()){
            fillCurrentTasks(ptr,clk,v,pq);
            if(pq.empty()){
                clk=v[ptr].enqTime;
                fillCurrentTasks(ptr,clk,v,pq);
            }
            ans.push_back(processTask(clk,pq));
        }
        while (pq.size()){
            ans.push_back(processTask(clk,pq));
        }
        return ans;
    }
};