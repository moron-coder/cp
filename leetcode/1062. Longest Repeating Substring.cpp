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
    int longestRepeatingSubstring(string s) {
        int n=s.size(),ans=0;
        int **dp=new int*[n];
        for(int i=0;i<n;i++) dp[i]=new int[n]();
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int curAns=0;
                if(s[i]==s[j]){
                    curAns++;
                    if(i+1<n && j+1<n) curAns+=dp[i+1][j+1];
                }
                dp[i][j]=curAns;
                ans=max(ans,curAns);
            }
        }
        return ans;
    }
};