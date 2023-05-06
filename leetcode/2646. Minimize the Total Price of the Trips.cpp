#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MAX_ANS=5000001;

    bool make(int st,int en,vector<vector<int>> &edges,unordered_map<int,int> &mp,int prev){
        if(st==en){
            mp[st]++;
            return true;
        }
        for(auto it:edges[st]){
            if(it==prev) continue;
            if(make(it,en,edges,mp,st)){
                mp[st]++;
                return true;
            }
        }
        return false;
    }

    int dp[51][2];

    int getCost(vector<vector<int>> &edges,int pos,unordered_map<int,int> &mp,vector<int> &price,bool canReduce,int prev){
        if(dp[pos][canReduce]!=-1) return dp[pos][canReduce];
        int ans=0,reduceCur=MAX_ANS,notReduceCur=MAX_ANS;
        notReduceCur=price[pos]*mp[pos];
        for(auto it:edges[pos]){
            if(it!=prev) notReduceCur+=getCost(edges,it,mp,price,true,pos);
        }
        if(canReduce){
            reduceCur=(price[pos]/2)*mp[pos];
            for(auto it:edges[pos]){
                if(it!=prev) reduceCur+=getCost(edges,it,mp,price,false,pos);
            }
        }
        ans=min(notReduceCur,reduceCur);
        return dp[pos][canReduce]=ans;
    }

    int minimumTotalPrice(int n, vector<vector<int>>& ar, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> edges(n,vector<int>());
        for(auto it:ar){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
        unordered_map<int,int> visCt;
        for(auto it:trips){
            make(it[0],it[1],edges,visCt,-1);
        }
        // disp(visCt);
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(auto it:visCt){
            if(dp[it.first][1]==-1){
                int small=getCost(edges,it.first,visCt,price,true,-1);
                ans+=small;
            }
        }
        return ans;
    }
};