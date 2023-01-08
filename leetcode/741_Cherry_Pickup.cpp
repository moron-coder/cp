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
    int di[2]={1,0};
    int dj[2]={0,1};
    int dp[51][51][51];

    int help(vector<vector<int>> &ar,int i1,int j1,int i2){
        int n=ar.size(),m=ar[0].size(),j2=i1+j1-i2,ans=-2,cur=0;
        if(dp[i1][j1][i2]!=-1) return dp[i1][j1][i2];
        if(ar[i1][j1]==1) cur++;
        if((i1!=i2 || j1!=j2) && ar[i2][j2]==1) cur++;
        for(int dir1=0;dir1<2;dir1++){
            int newI1=i1+di[dir1],newJ1=j1+dj[dir1];
            for(int dir2=0;dir2<2;dir2++){
                int newI2=i2+di[dir2],newJ2=j2+dj[dir2];
                if( newI1>=0 && newI1<n && newJ1>=0 && newJ1<m &&
                    newI2>=0 && newI2<n && newJ2>=0 && newJ2<m &&
                    ar[newI1][newJ1]!=-1 && ar[newI2][newJ2]!=-1
                ){
                    int sm=help(ar,newI1,newJ1,newI2);
                    if(sm!=-2) ans=max(ans,cur+sm);
                }
            }
        }
        // cout<<"{"<<i1<<","<<j1<<"} {"<<i2<<","<<j2<<"} returns "<<ans<<endl;
        return dp[i1][j1][i2]=ans;
    }

    int cherryPickup(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = help(ar,0,0,0);
        if(ans==-2) return 0;
        return ans;
    }
};