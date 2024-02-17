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

int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};

class Solution{    
    public:

    int minStepsToReachEnd(vector<vector<int>> &ar,int k){
        //  1 : obstacles
        //  0 : free cell
        queue<pii> q;
        int n=ar.size(),m=ar[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        q.push({0,0});
        vis[0][0]=true;
        q.push({-1,-1});
        int steps=0;

        while (q.size()){
            pii cur=q.front();
            q.pop();

            if(cur.first==-1){
                if(q.empty()){
                    break;
                }
                q.push({-1,-1});
                steps++;
            }else{
                int curI=cur.first,curJ=cur.second;
                if(curI==n-1 && curJ==m-1) return steps;
                for(int jumpRange=1;jumpRange<=k;jumpRange++){
                    for(int dir=0;dir<4;dir++){
                        int newI=curI+di[dir]*jumpRange, newJ=curJ+dj[dir]*jumpRange;
                        if(newI>=0 && newI<n && newJ>=0 && newJ<m && !ar[newI][newJ] && !vis[newI][newJ]){
                            q.push({newI,newJ});
                            vis[newI][newJ]=true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};