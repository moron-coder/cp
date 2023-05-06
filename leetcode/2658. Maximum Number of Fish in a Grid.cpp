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
    int di[4]={0,0,1,-1};
    int dj[4]={1,-1,0,0};

    int getFishCt(vector<vector<int>>& ar,int curI,int curJ,bool **vis){
        int n=ar.size(),m=ar[0].size(),ans=ar[curI][curJ];
        vis[curI][curJ]=true;
        for(int dir=0;dir<4;dir++){
            int newI=curI+di[dir],newJ=curJ+dj[dir];
            if(newI<n && newI>=0 && newJ<m && newJ>=0 && ar[newI][newJ] && !vis[newI][newJ]){
                ans+=getFishCt(ar,newI,newJ,vis);
            }
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& ar) {
        int ans=0,n=ar.size(),m=ar[0].size();
        bool **vis=new bool*[n];
        for(int i=0;i<n;i++) vis[i]=new bool[m]();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j] && !vis[i][j]) ans=max(ans,getFishCt(ar,i,j,vis));
            }
        }
        return ans;
    }
};