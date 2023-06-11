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
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        long long colSum=0,rowSum=0,remainingRows=n,remainingCols=n,ans=0;
        vector<int> rows(n,-1),cols(n,-1);
        for(int i=q.size()-1;i>=0;i--){
            long long idx=q[i][1],val=q[i][2];
            if(q[i][0] && cols[idx]==-1){
                // col
                ans+=val*remainingRows;
                remainingCols--;
            }
            if(!q[i][0] && rows[idx]==-1){
                ans+=val*remainingCols;
                remainingRows--;
            }
            // cout<<"ans = "<<ans<<endl;
        }
        return ans;
    }
};
