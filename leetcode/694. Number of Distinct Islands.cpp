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

int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& ar,vector<vector<bool>>& vis,vector<pii> &pts){
        int n=ar.size(),m=ar[0].size();
        vis[i][j]=true;
        pts.push_back({i,j});
        for(int dir=0;dir<4;dir++){
            int newI=i+di[dir],newJ=j+dj[dir];
            if(newI>=0 && newI<n && newJ>=0 && newJ<m && ar[newI][newJ] && !vis[newI][newJ]){
                dfs(newI,newJ,ar,vis,pts);
            }
        }
    }

    bool isSame(vector<pii> &v1,vector<pii> &v2){
        if(v1.size()!=v2.size()) return false;
        for(int i=0;i<v1.size();i++) if(v1[i].first!=v2[i].first || v1[i].second!=v2[i].second) return false;
        return true;
    }

    int numDistinctIslands(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<pii>> pts;        //  contains all the points corresponding to the corner[i] translated to the origin(0,0)
        vector<pii> corners;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j] && !vis[i][j]){
                    corners.push_back({i,j});
                    vector<pii> curPts;
                    dfs(i,j,ar,vis,curPts);
                    for(int itr=curPts.size()-1;itr>=0;itr--) curPts[itr].first-=curPts[0].first,curPts[itr].second-=curPts[0].second;
                    sort(curPts.begin(),curPts.end());
                    pts.push_back(curPts);
                }
            }
        }
        // debug
        cout<<"showing pts:\n";
        for(int i=0;i<pts.size();i++){
            for(auto it:pts[i]) cout<<"{"<<it.first<<","<<it.second<<"} ";
            cout<<endl;
        }
        // debug
        unordered_set<int> dontCount;
        int ans=0;
        for(int i=0;i<pts.size();i++){
            if(dontCount.count(i)) continue;
            for(int j=i+1;j<pts.size();j++){
                if(dontCount.count(j)) continue;
                if(isSame(pts[i],pts[j])) dontCount.insert(j);
            }
            ans++;
        }
        return ans;
    }
};