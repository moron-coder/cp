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

int di[]={0,1};
int dj[]={1,0};

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size();
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                if(ar[i][j]){
                    int ct=0;
                    if(i+1<n && ar[i+1][j]){
                        ct++;
                    }
                    if(j+1<m && ar[i][j+1]){
                        ct++;
                    }
                    ar[i][j]=ct;
                }
            }
        }
        if(!ar[0][0]) return true;
        queue<pii> q;
        q.push({0,0});
        ar[0][0]=-1;
        while (q.size()){
            pii tp=q.front();
            q.pop();
            if(q.empty() && (tp.first!=n-1 || tp.second!=m-1) && (tp.first!=0 || tp.second!=0)){
                return true;
            }
            int curI=tp.first,curJ=tp.second;
            for(int dir=0;dir<2;dir++){
                int newI=curI+di[dir],newJ=curJ+dj[dir];
                if(newI<n && newI>=0 && newJ<m && newJ>=0 && ar[newI][newJ]!=-1 && ar[newI][newJ]>=1){
                    q.push({newI,newJ});
                    ar[newI][newJ]=-1;
                }
            }
        }
        return false;
    }
};

/*
[
    [1,1,1,1,1,1],
    [1,0,0,1,0,1],
    [1,1,1,1,0,1],
    [0,0,0,1,1,1],
]


[[1,1,1,1,1,1],[1,0,0,1,0,1],[1,1,1,1,0,0],[0,0,0,1,1,1]]
*/