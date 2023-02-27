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
    pii des;

    int vis[101][101],sufI[101][101],preI[101][101],sufJ[101][101],preJ[101][101];

    bool isOk(int n,int m,int curI,int curJ){
        if(vis[curI][curJ]!=-1) return vis[curI][curJ];
        if(curI==des.first && curJ==des.second) return true;
        vis[curI][curJ]=false;
        return vis[curI][curJ]=(isOk(n,m,preI[curI][curJ],curJ) || isOk(n,m,sufI[curI][curJ],curJ) || 
        isOk(n,m,curI,preJ[curI][curJ]) || isOk(n,m,curI,sufJ[curI][curJ]));
    }

    bool hasPath(vector<vector<int>>& ar, vector<int>& start, vector<int>& destination) {
        int n=ar.size(),m=ar[0].size();
        des.first=destination[0],des.second=destination[1];
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(ar[i][j]){
                    sufI[i][j]=-1;
                    continue;
                }
                if(i+1>=n || ar[i+1][j]) sufI[i][j]=i;
                else sufI[i][j]=sufI[i+1][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]){
                    preI[i][j]=-1;
                    continue;
                }
                if(i==0 || ar[i-1][j]) preI[i][j]=i;
                else preI[i][j]=preI[i-1][j];
            }
        }
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++){
                if(ar[i][j]){
                    sufJ[i][j]=-1;
                    continue;
                }
                if(j+1>=m || ar[i][j+1]) sufJ[i][j]=j;
                else sufJ[i][j]=sufJ[i][j+1];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(ar[i][j]){
                    preJ[i][j]=-1;
                    continue;
                }
                if(j==0 || ar[i][j-1]) preJ[i][j]=j;
                else preJ[i][j]=preJ[i][j-1];
            }
        }
        memset(vis,-1,sizeof(vis));
        return isOk(n,m,start[0],start[1]);
    }
};