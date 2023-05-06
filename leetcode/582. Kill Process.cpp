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
    void bfs(unordered_map<int,vector<int>> &mp,int kill,vector<int> &ans){
        queue<int> q;
        q.push(kill);
        while (q.size()){
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(auto it:mp[cur]){
                q.push(it);
            }
        }
    }

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>> mp;
        vector<int> ans;
        for(int i=0;i<ppid.size();i++) if(ppid[i]) mp[ppid[i]].push_back(pid[i]);
        bfs(mp,kill,ans);
        return ans;
    }
};