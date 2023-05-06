#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

class dsu{
    int *par,*rank;
    int n;
    public:

    dsu(int n){
        this->n=n;
        par=new int[n]();
        rank=new int[n]();
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }

    int getPar(int x){
        if(par[x]==x) return x;
        return par[x]=getPar(par[x]);
    }

    void merge(int x,int y){
        int px=getPar(x),py=getPar(y);
        if(rank[px]<rank[py]){
            par[px]=py;
        }else if(rank[px]>rank[py]){
            par[py]=px;
        }else{
            par[px]=py;
            rank[py]++;
        }
    }
};

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

class Solution {
public:
    vector<int> numIslands2(int n, int m, vector<vector<int>>& ar) {
        int ans=0;
        set<pii> st;
        vector<int> ret;
        dsu unf(n*m);
        for(auto it:ar){
            int cur=it[0]*m+it[1],i=it[0],j=it[1],mergedCount=0,prevSets=0;
            if(st.count({i,j})){
                ret.push_back(ans);
                continue;
            }
            unordered_set<int> nbParents;
            for(int dir=0;dir<4;dir++){
                int newI=i+di[dir],newJ=j+dj[dir];
                if(newI>=0 && newI<n && newJ>=0 && newJ<m && st.count({newI,newJ})){
                    int tmp=unf.getPar(newI*m+newJ);
                    nbParents.insert(tmp);
                }
            }
            ans-=(nbParents.size()-1);
            for(int dir=0;dir<4;dir++){
                int newI=i+di[dir],newJ=j+dj[dir];
                if(newI>=0 && newI<n && newJ>=0 && newJ<m && st.count({newI,newJ})){
                    unf.merge(newI*m+newJ,i*m+j);
                }
            }
            ret.push_back(ans);
            st.insert({i,j});
        }
        return ret;
    }
};