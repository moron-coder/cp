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


    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pii> indexQueries;
        for(int i=0;i<queries.size();i++) indexQueries.push_back({queries[i],i});       //  [queries[i]-x,queries[i]]
        sort(indexQueries.begin(),indexQueries.end());
        for(auto &it:logs) swap(it[0],it[1]);       //  time,server_id
        sort(logs.begin(),logs.end());
        int i=0,logsPtr=0;
        queue<pii> q;     //  {time,server_id}
        unordered_map<int,int> mp;      //  {server_id, fq}
        vector<int> ans(indexQueries.size(),-1);
        for(int j=0;j<indexQueries.size();j++){
            while (logsPtr<logs.size() && logs[logsPtr][0]<=indexQueries[j].first){
                mp[logs[logsPtr][1]]++;
                q.push({logs[logsPtr][0],logs[logsPtr][1]});
                logsPtr++;
            }
            while (q.size() && q.front().first<indexQueries[j].first-x){
                pii top = q.front();
                q.pop();
                mp[top.second]--;
                if(mp[top.second]==0){
                    mp.erase(top.second);
                }
            }
            ans[indexQueries[j].second]=n-(mp.size());
        }
        return ans;
    }
};