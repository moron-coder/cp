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
    bool canChange(vector<vector<int>>& ar,int i,int j,int dir){
        int newI=i+di[dir],newJ=j+dj[dir],n=ar.size(),m=ar[0].size();
        if(newI>=0 && newI<n && newJ>=0 && newJ<m && !ar[newI][newJ]) return false;
        return true;
    }

    int shortestDistance(vector<vector<int>>& ar, vector<int>& start, vector<int>& destination) {
        pii st,en;
        int ans=0;
        int vis[101][101][4];
        memset(vis,-1,sizeof(vis));
        st.first=start[0],st.second=start[1];
        en.first=destination[0],en.second=destination[1];
        queue<vector<int>> q;
        int n=ar.size(),m=ar[0].size();
        q.push({st.first,st.second,0});
        vis[st.first][st.second][0]=1;
        q.push({st.first,st.second,1});
        vis[st.first][st.second][1]=1;
        q.push({st.first,st.second,2});
        vis[st.first][st.second][2]=1;
        q.push({st.first,st.second,3});
        vis[st.first][st.second][3]=1;
        q.push({-1,-1});
        while (q.size()){
            vector<int> tp = q.front();
            q.pop();
            if(tp[0]==-1){
                if(q.empty()) break;
                q.push({-1,-1,-1});
                ans++;
            }else{
                int curI=tp[0],curJ=tp[1],curDir=tp[2];
                if(curI==en.first && curJ==en.second && canChange(ar,curI,curJ,curDir)) return ans;
                if(canChange(ar,curI,curJ,curDir)){
                    for(int dir=0;dir<4;dir++){
                        if(canChange(ar,curI,curJ,dir)) continue;
                        int newI=curI+di[dir],newJ=curJ+dj[dir];
                        if(vis[newI][newJ][dir]==-1){
                            q.push({newI,newJ,dir});
                            vis[newI][newJ][dir]=1;
                        }
                    }
                }else{
                    int newI=curI+di[curDir],newJ=curJ+dj[curDir];
                    if(vis[newI][newJ][curDir]==-1){
                        q.push({newI,newJ,curDir});
                        vis[newI][newJ][curDir]=1;
                    }
                }
            }
        }
        return -1;
    }
};