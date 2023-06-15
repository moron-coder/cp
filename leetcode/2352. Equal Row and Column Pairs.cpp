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

    bool isEq(vector<vector<int>> &ar,int rIdx,int cIdx){
        for(int i=0;i<ar.size();i++){
            if(ar[rIdx][i]!=ar[i][cIdx]) return false;
        }
        return true;
    }

    int equalPairs(vector<vector<int>>& ar) {
        int ans=0,n=ar.size(),m=ar[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isEq(ar,i,j)) ans++;
            }
        }
        return ans;
    }
};