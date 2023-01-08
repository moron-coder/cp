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
    int minimumObstacles(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size();
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<vector<bool>> vis(n,vector(m,false));
        pq.push({ar[0][0],0});
        vis[0][0]=true;
        while (pq.size()){
            pii cur=pq.top();
            pq.pop();
            int curI=cur.second/m,curJ=cur.second%m;
            if(curI==n-1 && curJ==m-1) return cur.first;
            for(int dir=0;dir<4;dir++){
                int newI=curI+di[dir],newJ=curJ+dj[dir];
                if(newI>=0 && newI<n && newJ>=0 && newJ<m && !vis[newI][newJ]){
                    pq.push({cur.first+ar[newI][newJ],newI*m+newJ});
                    vis[newI][newJ]=true;
                }
            }
        }
        return -1;
    }
};