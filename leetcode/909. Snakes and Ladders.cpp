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
    int snakesAndLadders(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size(),steps=0;
        queue<pii> q;
        map<int,int> seen;
        seen[0]=0;
        q.push({0,0});
        q.push({-1,-1});
        while (q.size()){
            pii cur=q.front();
            q.pop();
            if(cur.first==-1){
                if(q.empty()) break;
                q.push({-1,-1});
                steps++;
                // cout<<"Step "<<steps-1<<" over\n";
            }else{
                // cout<<cur.first<<" : ";
                if(cur.first==n*m-1) return cur.second;
                int curI=cur.first/m,curJ=-1;
                if(curI&1){
                    curJ=m-1-(cur.first%m);
                }else{
                    curJ=cur.first%m;
                }
                
                for(int i=1;i<=6;i++){
                    int newPos=min(n*m-1,cur.first+i);
                    // ladder or snake
                    int newI=newPos/m,newJ=-1;
                    if(newI&1){
                        newJ=m-1-(newPos%m);
                    }else{
                        newJ=newPos%m;
                    }
                    if(ar[n-1-newI][newJ]!=-1){
                        if(seen.count(ar[n-1-newI][newJ]-1)) continue;
                        newPos=ar[n-1-newI][newJ]-1;
                        seen[newPos]=steps+1;
                        q.push({newPos,steps+1});
                        // cout<<"going to "<<newPos<<" from "<<cur.first<<endl;
                        continue;
                    }
                    // ladder or snake
                    // cout<<"no l or s at "<<newPos<<endl;
                    if(!seen.count(newPos)){
                        seen[newPos]=steps+1;
                        q.push({newPos,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};

/*
[
    [1,1,-1],
    [1,1,1],
    [-1,1,1]
]
*/