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
    int minJumps(vector<int>& ar) {
        int n=ar.size(),steps=0;
        unordered_map<int,vector<int>> occurs;
        for(int i=0;i<n;i++) occurs[ar[i]].push_back(i);
        set<int> visIdx,visVal;
        queue<int> q;
        q.push(0);
        visIdx.insert(0);
        q.push(-1);
        while (q.size()){
            int cur=q.front();
            q.pop();
            if(cur==-1){
                if(q.empty()) break;
                q.push(-1);
                steps++;
            }else{
                if(cur==n-1) return steps;
                if(!visVal.count(ar[cur])){
                    visVal.insert(ar[cur]);
                    for(auto it:occurs[ar[cur]]){
                    if(!visIdx.count(it)){
                        q.push(it);
                        visIdx.insert(it);
                    }
                }
                }
                if(cur && !visIdx.count(cur-1)){
                    q.push(cur-1);
                    visIdx.insert(cur-1);
                }
                if(cur+1<n && !visIdx.count(cur+1)){
                    q.push(cur+1);
                    visIdx.insert(cur+1);
                }
            }
        }
        return -1;
    }
};