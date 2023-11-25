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
public:
    int MAX_ANS = 100000;

    int help(vector<vector<int>> &ar,int curI,int curJ){
        int ans = MAX_ANS;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(ar[i][j]>1){
                    ar[i][j]--;
                    ar[curI][curJ]=1;
                    int curOpsCt = abs(i-curI)+abs(j-curJ), small=0;
                    for(int i1=0;i1<3;i1++){
                        for(int j1=0;j1<3;j1++){
                            if(ar[i1][j1]==0){
                                small = help(ar,i1,j1);
                            }
                        }
                    }
                    ans=min(ans,curOpsCt+small);
                    ar[curI][curJ]=0;
                    ar[i][j]++;
                }
            }
        }
        return ans==MAX_ANS?0:ans;
    }

    int minimumMoves(vector<vector<int>>& ar) {
        int ans= MAX_ANS;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(!ar[i][j]){
                    ans = min(help(ar,i,j),ans);
                }
            }
        }
        return ans;
    }
};