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

ll di[]={1,-1,0,0};
ll dj[]={0,0,1,-1};

class Solution {
public:

    vector<int> maxPoints(vector<vector<int>>& ar, vector<int>& qry) {
        int n=ar.size(),m=ar[0].size(),pt=0;
        vector<int> ans(qry.size(),0),ret(n,0);
        vector<pii> v;
        for(int i=0;i<qry.size();i++) v.push_back({qry[i],i});
        sort(v.begin(),v.end());
        priority_queue<pii,vector<pii>,greater<pii>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        q.push({ar[0][0],0});
        vis[0][0]=true;
        while (q.size() && pt<qry.size()){
            pii tp=q.top();
            q.pop();
            if(tp.first>=v[pt].first){
                while(pt+1<v.size() && v[pt+1].first<=tp.first) pt++;
                pt++;
                q.push(tp);
            }else{
                int oldI=tp.second/m,oldJ=tp.second%m;
                ans[pt]++;
                for(int dir=0;dir<4;dir++){
                    int newI=oldI+di[dir],newJ=oldJ+dj[dir];
                    if(newI>=0 && newI<n && newJ>=0 && newJ<m && !vis[newI][newJ]){
                        vis[newI][newJ]=true;
                        q.push({ar[newI][newJ],newI*m+newJ});
                    }
                }
            }
        }
        ret[v[0].second]=ans[0];
        for(int i=1;i<ans.size();i++) ans[i]+=ans[i-1],ret[v[i].second]=ans[i];
        return ret;
    }
};