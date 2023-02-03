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
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size(),sum=0;
        int *dp=new int[n](); 
        dp[0]=1;
        dp[1]--;
        for(int i=0;i<n;i++){
            sum+=dp[i];
            if(s[i]=='0' && sum>0){
                if(i==n-1) return true;
                if(i+minJump<n) dp[i+minJump]++;
                if(i+maxJump+1<n) dp[i+maxJump+1]--;
            }
        }
        return false;
    }
};