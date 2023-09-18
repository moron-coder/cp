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
        while (!(sx==tx && sy==ty)){
            if(tx<sx || ty<sy) return false;
            if(tx>ty){
                // tx is JUST greater than ty after doing subtraction many times
                // find the number greater than ty
                tx -= max(1,min(tx-sx,tx-ty)/ty)*ty;      //  max(1,..) bcz subtract ATLEAST 1 times
            }else{
                ty -= max(1,min(ty-sy,ty-tx)/tx)*tx;      //  max(1,..) bcz subtract ATLEAST 1 times
            }
        }
        return true;
    }
};