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
    int minCost(vector<int>& ar, int k) {
        int n=ar.size();
        int *dp=new int[n+1]();
        for(int i=1;i<=n;i++){
            int tLen=0,ans=INT_MAX;
            int *curFq=new int[n+1]();
            for(int j=i;j>=1;j--){
                curFq[ar[j-1]]++;
                if(curFq[ar[j-1]]==2){
                    tLen+=2;
                }else if(curFq[ar[j-1]]>2){
                    tLen++;
                }
                ans=min(ans,tLen+k+dp[j-1]);
            }
            dp[i]=ans;
        }
        return dp[n];
    }
};