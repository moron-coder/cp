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
    int getNextPos(vector<vector<int>> &ar,int endDate){
        int lo=0,hi=ar.size()-1,ans=-1;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(ar[mid][0]>endDate){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;
    }

    int help(vector<vector<int>> &ar,int pos,int k,int **dp){
        int n=ar.size();
        if(k==0 || pos>=n) return 0;
        if(dp[pos][k]!=-1) return dp[pos][k];
        int attendAns=ar[pos][2],notAttendAns=help(ar,pos+1,k,dp),nextPos = getNextPos(ar,ar[pos][1]);
        if(nextPos!=-1){
            attendAns=help(ar,nextPos,k-1,dp)+ar[pos][2];
        }
        return dp[pos][k] = max(attendAns,notAttendAns);
    }

    int maxValue(vector<vector<int>>& ar, int k) {
        sort(ar.begin(),ar.end());
        int n=ar.size();
        int **dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[k+1]();
            for(int j=0;j<=k;j++) dp[i][j]=-1;
        }
        return help(ar,0,k,dp);
    }
};