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

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0}; 

class Solution {
    void calcSafetyFactors(vector<vector<int>> &safetyFactors, vector<vector<int>> &ar){
        int n=ar.size(),m=ar[0].size(),steps=0;

        queue<int> q;
        unordered_set<int> vis;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(ar[i][j]){
                    q.push(i*m+j);
                    vis.insert(i*m+j);
                }
            }
        }
        
        q.push(-1);

        while (q.size()){
            int cur=q.front();
            q.pop();
            if(cur==-1){
                if(q.empty()) break;
                q.push(-1);
                steps++;
            }else{
                int curI = cur/m, curJ = cur%m;
                safetyFactors[curI][curJ]=steps;
                for(int dir=0;dir<4;dir++){
                    int newI = curI+di[dir], newJ = curJ+dj[dir];
                    if(newI>=0 && newI<n && newJ>=0 && newJ<m && !vis.count(newI*m+newJ)){
                        q.push(newI*m+newJ);
                        vis.insert(newI*m+newJ);
                    }
                }
            }
        }
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size();
        vector<vector<int>> safetyFactors(n,vector<int>(m,0));
        calcSafetyFactors(safetyFactors, ar);

        priority_queue<pii> pq;         //  {safety_factor, index}
        unordered_set<int> vis;
        pq.push({safetyFactors[0][0],0});
        vis.insert(0);

        while (pq.size()){
            pii cur=pq.top();
            pq.pop();

            int safetyFac = cur.first, curI = cur.second/m, curJ = cur.second%m;
            if(curI==n-1 && curJ==m-1){
                return safetyFac;
            }
            for(int dir=0;dir<4;dir++){
                int newI = curI+di[dir], newJ = curJ+dj[dir];
                if(newI>=0 && newI<n && newJ>=0 && newJ<m && !vis.count(newI*m+newJ)){
                    pq.push({min(safetyFac, safetyFactors[newI][newJ]),
                            newI*m+newJ});
                    vis.insert(newI*m+newJ);
                }
            }
        }
        return -1;
    }
};