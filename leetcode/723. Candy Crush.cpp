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
    void shiftDown(vector<vector<int>> &ar,vector<vector<int>> &crush){
        int n=ar.size(),m=ar[0].size();
        for(int j=0;j<m;j++) if(crush[n-1][j]) ar[n-1][j]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int tmp=ar[i][j],depth=crush[i+1][j];
                ar[i][j]=0;
                if(!crush[i][j]) ar[depth+i][j]=tmp;
                crush[i][j]+=depth;
            }
        }
    }

    bool makeCrush(vector<vector<int>> &crush,vector<vector<int>> &dpV,vector<vector<int>> &dpH){
        bool ans=false;
        int n=crush.size(),m=crush[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dpV[i][j]>=3){
                    crush[i][j]=1;
                    ans=true;
                    for(int k=i;dpV[k][j]!=1;k++){
                        crush[k+1][j]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dpH[i][j]>=3){
                    crush[i][j]=1;
                    ans=true;
                    for(int k=j;dpH[i][k]!=1;k++){
                        crush[i][k+1]=1;
                    }
                }
            }
        }
        return ans;
    }

    bool checkMark(vector<vector<int>> &ar){
        int n=ar.size(),m=ar[0].size();
        bool isChange=false;
        vector<vector<int>> crush(n,vector<int>(m,0)),dpV(n,vector<int>(m,1)),dpH(n,vector<int>(m,1));
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(ar[i][j] && ar[i+1][j]==ar[i][j]) dpV[i][j]+=dpV[i+1][j];
            }
        }
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){
                if(ar[i][j] && ar[i][j+1]==ar[i][j]) dpH[i][j]+=dpH[i][j+1];
            }
        }
        if(makeCrush(crush,dpV,dpH)){
            shiftDown(ar,crush);
            return true;
        }
        return false;
    }

    vector<vector<int>> candyCrush(vector<vector<int>>& ar) {
        while (checkMark(ar));
        return ar;
    }
};