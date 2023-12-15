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
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (!(tx==sx && ty==sy)){
            if(tx<sx || ty<sy) return false;
            if(tx>ty){
                int dif = min(tx-ty,tx-sx);
                int totalSubs = (dif/ty)*ty;
                // tx-=ty;
                tx-=totalSubs;
                if(totalSubs==0) tx-=ty;
            }else{
                // ty-=tx;
                int dif = min(ty-tx,ty-sy);
                int totalSubs = (dif/tx)*tx;
                ty-=totalSubs;
                if(totalSubs==0) ty-=tx;
            }
        }
        return true;
    }
};