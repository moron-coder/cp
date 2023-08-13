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
    int maxIncreasingGroups(vector<int>& ar) {
        sort(ar.begin(),ar.end());
        int req=1,extras=0,n=ar.size();
        for(int i=0;i<n;i++){
            if(ar[i]+extras>=req){
                extras = ar[i]+extras-req;
                req++;
            }else{
                extras+=ar[i];
            }
        }
        return req-1;
    }
};