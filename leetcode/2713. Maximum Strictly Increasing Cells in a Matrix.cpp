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
    int maxIncreasingCells(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size(),ret=0;
        vector<int> rowMaxAns(n,0),colMaxAns(m,0);
        map<int,vector<int>> valToPos;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) valToPos[ar[i][j]].push_back(i*m+j);

        for(auto it:valToPos){
            int curVal = it.first;
            vector<int> tmpAns;                  //  these will be added to rowMaxAns and colMaxAns in bulk
            for(auto curPos:it.second){
                int curI=curPos/m,curJ=curPos%m;
                int rowAns = max(1,1+rowMaxAns[curI]);
                int colAns = max(1,1+colMaxAns[curJ]);
                tmpAns.push_back(max(rowAns,colAns));
            }

            for(int posIdx=0;posIdx<tmpAns.size();posIdx++){
                int pos = it.second[posIdx], curI=pos/m, curJ=pos%m, bestAns = tmpAns[posIdx];
                rowMaxAns[curI]=max(rowMaxAns[curI],bestAns);
                colMaxAns[curJ]=max(colMaxAns[curJ],bestAns);
                ret=max(ret,bestAns);
            }
        }
        return ret;
    }
};