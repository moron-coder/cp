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

int di[]={-1,-1,1,1,-2,-2,2,2};
int dj[]={-2,2,-2,2,-1,1,-1,1};

class Solution {
public:
    int minKnightMoves(int x, int y) {
        bool vis[601][601];
        memset(vis,false,sizeof(vis));
        queue<pii> q;
        q.push({0,0});
        q.push({-1000,-1000});
        int ans=0;
        while (q.size()){
            pii cur=q.front();
            q.pop();
            if(cur.first==-1000){
                if(q.empty()) break;
                q.push({-1000,-1000});
                ans++;
            }else{
                cout<<"in "<<ans<<" steps, I reached {"<<cur.first<<","<<cur.second<<"}\n";
                if(cur.first==x && cur.second==y){
                    return ans;
                }
                for(int it=0;it<8;it++){
                    int newI=cur.first+di[it],newJ=cur.second+dj[it];
                    if(newI>=-300 && newI<=300 && newJ>=-300 && newJ<=300 && !vis[newI+300][newJ+300]){
                        vis[newI+300][newJ+300]=true;
                        q.push({newI,newJ});
                    }
                }
            }
        }
        return -1;
    }
};