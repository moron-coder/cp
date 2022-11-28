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
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& ar) {
        int n=ar.size(),m=ar[0].size();
        vector<int> oneRow(n,0),zerosRow(n,0),onesCol(m,0),zerosCol(m,0);
        for(int i=0;i<n;i++){
            int oCt=0,zCt=0;
            for(int j=0;j<m;j++){
                if(ar[i][j]==1) oCt++;
                else if(ar[i][j]==0) zCt++;
            }
            oneRow[i]=oCt;
            zerosRow[i]=zCt;
        }
        for(int j=0;j<m;j++){
            int oCt=0,zCt=0;
            for(int i=0;i<n;i++){
                if(ar[i][j]==1) oCt++;
                else if(ar[i][j]==0) zCt++;
            }
            onesCol[j]=oCt;
            zerosCol[j]=zCt;
        }
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) ans[i][j]=oneRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
        }
        return ans;
    }
};