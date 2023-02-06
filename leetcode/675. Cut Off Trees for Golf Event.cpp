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

int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

class Solution {
public:
    int getStepsCt(vector<vector<int>> &ar,int startI,int startJ,int endI,int endJ){
        int ans=0,n=ar.size(),m=ar[0].size();
        queue<pii> q;
        bool vis[n][m];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j]=false;
        q.push({startI,startJ});
        vis[startI][startJ]=true;
        q.push({-1,-1});
        while (q.size()){
            pii cur=q.front();
            q.pop();
            if(cur.first==-1){
                if(q.empty()) break;
                ans++;
                q.push({-1,-1});
            }else{
                int curI=cur.first,curJ=cur.second;
                if(curI==endI && curJ==endJ) return ans;
                for(int dir=0;dir<4;dir++){
                    int newI=curI+di[dir],newJ=curJ+dj[dir];
                    if(newI>=0 && newI<n && newJ>=0 && newJ<m && (ar[newI][newJ]>=1) && !vis[newI][newJ]){
                        q.push({newI,newJ});
                        vis[newI][newJ]=true;
                    }
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& ar) {
        if(ar[0][0]==0) return -1;
        int n=ar.size(),m=ar[0].size(),ans=0;
        vector<vector<int>> vec;
        vec.push_back({INT_MIN,0,0});
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]>1) vec.push_back({ar[i][j],i,j});
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size()-1;i++){
            int sm=getStepsCt(ar,vec[i][1],vec[i][2],vec[i+1][1],vec[i+1][2]);
            if(sm==-1){
                return -1;
            }
            ans+=sm;
        }
        return ans;
    }
};