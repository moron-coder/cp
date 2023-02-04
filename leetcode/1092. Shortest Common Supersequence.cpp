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
    int dp[1001][1001],lenDp[1001][1001];     
    //  dp[i][j]=0 : pick s1[i]
    //  dp[i][j]=1 : pick s2[j] 
    //  dp[i][j]=2 : pick any of s1[i] or s2[j] 

    int help(string &s1,string &s2,int i,int j){
        int n=s1.size(),m=s2.size();
        if(lenDp[i][j]!=-1) return lenDp[i][j];
        if(i>=n && j>=m) return 0;
        if(i>=n){
            dp[i][j]=1;
            return lenDp[i][j]=1+help(s1,s2,i,j+1);
        }
        if(j>=m){
            dp[i][j]=0;
            return lenDp[i][j]=1+help(s1,s2,i+1,j);
        }
        if(s1[i]==s2[j]){
            dp[i][j]=2;
            return lenDp[i][j]=1+help(s1,s2,i+1,j+1);
        }
        int p1=1+help(s1,s2,i+1,j),p2=1+help(s1,s2,i,j+1);
        if(p1<p2){
            dp[i][j]=0;
            return lenDp[i][j]=p1;
        }
        dp[i][j]=1;
        return lenDp[i][j]=p2;
    }

    string shortestCommonSupersequence(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        memset(lenDp,-1,sizeof(lenDp));
        int n=s1.size(),m=s2.size();
        int len=help(s1,s2,0,0),i=0,j=0;
        string ans;
        for(int it=0;it<len;it++){
            if(dp[i][j]==0){
                ans.push_back(s1[i]);
                i++;
            }else if(dp[i][j]==1){
                ans.push_back(s2[j]);
                j++;
            }else if(dp[i][j]==2){
                ans.push_back(s1[i]);
                i++,j++;
            }else{                
                cout<<"invalid!!\n";
                return "";
            }
        }
        return ans;
    }
};