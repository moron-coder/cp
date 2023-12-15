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
    int numSubmatrixSumTarget(vector<vector<int>>& ar, int k) {
        int ans=0,n=ar.size(),m=ar[0].size();
        vector<vector<int>> prefixAr(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            prefixAr[i][0]=ar[i][0];
            for(int j=1;j<m;j++) prefixAr[i][j]=ar[i][j]+prefixAr[i][j-1];
        }
        for(int lfCol=0;lfCol<m;lfCol++){
            for(int rtCol=lfCol;rtCol<m;rtCol++){
                unordered_map<int,int> mp;
                int sum=0;
                for(int i=0;i<n;i++){
                    sum+=prefixAr[i][rtCol]-prefixAr[i][lfCol]+ar[i][lfCol];
                    ans+=mp[sum-k];
                    if(sum==k) ans++;
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};