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
    bool checkArray(vector<int>& ar, int k) {
        int n=ar.size(),sum=0,runningDel=0;
        vector<int> del(n+1,0);
        for(int i=0;i<n;i++){
            runningDel+=del[i];
            ar[i]+=runningDel;
            if(ar[i]<0) return false;
            if(i+k<=n) del[i+k]+=ar[i];
            else if(ar[i]) return false;
            runningDel-=ar[i];
        }
        return runningDel+del.back()==0;
    }
};