#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

class Solution {
public:
    int getPointFromCoords(int i,int j,int m){
        return i*m+j;
    }

    pii getCoordsFromPoints(int pt,int m){
        return {pt/m,pt%m};
    }

    int minimumVisitedCells(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size(),visCt=1;
        cout<<n<<" "<<m<<endl;
        // vector<vector<pii>> maxIJ(n,vector<pii>(m,{-1,-1}));
        vector<int> maxReachedRowForCol(m,0),maxReachedColForRow(n,0);
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pii> q;
        q.push({0,0});
        vis[0][0]=true;
        q.push({-1,-1});
        while (q.size()){
            pii tp=q.front();
            // cout<<"at ("<<tp.first<<", "<<tp.second<<")\n";
            q.pop();
            if(tp.first==-1){
                if(q.empty()) break;
                q.push({-1,-1});
                visCt++;
            }else{
                int i=tp.first,j=tp.second,minI=i+1,minJ=j+1;
                if(i==n-1 && j==m-1) return visCt;
                // if(maxReachedRowForCol[j]!=-1 && maxReachedRowForCol[j]<i){
                //     cout<<i<<","<<j<<" me kch to gadbad hai\n";
                // }
                // if(ar[i][j]<=0) continue;
                // cout<<"at ("<<tp.first<<", "<<tp.second<<") visCt: "<<visCt<<endl;
                // if(ar[i][j]==0){
                //     cout<<"at ("<<tp.first<<", "<<tp.second<<")\n";
                // }
                if(maxReachedRowForCol[j]!=-1){
                    minI=maxReachedRowForCol[j]+1;
                }
                if(maxReachedColForRow[i]!=-1){
                    minJ=maxReachedColForRow[i]+1;
                }
                minI=min(minI,n-1);
                minJ=min(minJ,m-1);
                // if(i==14 && j==47){
                //     cout<<"ar[i][j] is "<<ar[i][j]<<endl;
                //     cout<<"i : ["<<minI<<","<<min(n-1,ar[i][j]+i)<<"]\n";
                //     cout<<"j : ["<<minJ<<","<<min(m-1,ar[i][j]+j)<<"]\n";
                // }
                for(int curI=minI;curI<=min(n-1,ar[i][j]+i);curI++){
                    // if(ar[i][j]==0) cout<<"I can reach ("<<curI<<","<<j<<") from ("<<i<<","<<j<<")\n";
                    if(vis[curI][j]) continue;
                    q.push({curI,j});
                    maxReachedRowForCol[j]=max(maxReachedRowForCol[j],curI);
                    maxReachedColForRow[curI]=max(maxReachedColForRow[curI],j);
                    vis[curI][j]=true;
                }
                // maxReachedRowForCol[j]=max(maxReachedRowForCol[j],min(n-1,ar[i][j]+i));
                for(int curJ=minJ;curJ<=min(m-1,ar[i][j]+j);curJ++){
                    // if(ar[i][j]==0) cout<<"I can reach ("<<i<<","<<curJ<<") from ("<<i<<","<<j<<")\n";
                    if(vis[i][curJ]) continue;
                    q.push({i,curJ});
                    maxReachedRowForCol[curJ]=max(maxReachedRowForCol[curJ],i);
                    maxReachedColForRow[i]=max(maxReachedColForRow[i],curJ);
                    vis[i][curJ]=true;
                }
                // maxReachedColForRow[i]=max(maxReachedColForRow[i],min(m-1,ar[i][j]+j));
            }
        }
        return -1;
    }
};
