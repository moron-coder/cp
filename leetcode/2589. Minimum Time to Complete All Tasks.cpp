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
    const static int MAX_SZ=2000;

    static bool cmp(vector<int> &x,vector<int> &y){
        return x[1]<y[1];
    }

    void help(vector<vector<int>> &ar,int pos,int *dp){
        if(pos>=ar.size()) return;
        int ct=0;
        for(int i=ar[pos][1];i>=ar[pos][0] && ct<ar[pos][2];i--){
            if(dp[i]) ct++;
        }
        if(ct!=ar[pos][2]){
            int d=ar[pos][2]-ct;
            for(int i=ar[pos][1];i>=ar[pos][0] && d;i--){
                if(!dp[i]){
                    dp[i]=1;
                    d--;
                }
            }
        }
        help(ar,pos+1,dp);
    }

    int findMinimumTime(vector<vector<int>>& ar) {
        sort(ar.begin(),ar.end(),cmp);
        int *dp=new int[MAX_SZ+1]();
        help(ar,0,dp);
        int ans=0;
        for(int i=0;i<=MAX_SZ;i++){
            ans+=dp[i];
        }
        return ans;
    }
};