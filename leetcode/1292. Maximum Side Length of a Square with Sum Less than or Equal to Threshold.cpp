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
    bool isOk(vector<vector<int>> &sums,int len,int k){
        int n=sums.size(),m=sums[0].size();
        for(int i=len-1;i<n;i++){
            for(int j=len-1;j<m;j++){
                int cur=sums[i][j];
                if(i-len>=0) cur-=sums[i-len][j];
                if(j-len>=0) cur-=sums[i][j-len];
                if(i-len>=0 && j-len>=0) cur+=sums[i-len][j-len];
                if(cur>k) return false;
            }
        }
        return true;
    }

    int maxSideLength(vector<vector<int>>& ar, int k) {
        int n=ar.size(),m=ar[0].size(),lo=0,hi=min(n,m),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i) ar[i][j]+=ar[i-1][j];
                if(j) ar[i][j]+=ar[i][j-1];
                if(i&&j) ar[i][j]-=ar[i-1][j-1];
            }
        }
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isOk(ar,mid,k)){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans;
    }
};