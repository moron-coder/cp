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
    int minimumOperations(string s) {
        int n=s.size(),ans=n;
        int suf0[n], suf5[n];
        memset(suf0,-1,sizeof(suf0));
        memset(suf5,-1,sizeof(suf5));
        for(int i=n-1;i>=0;i--){
            if(i<n-1){
                suf0[i]=suf0[i+1];
                suf5[i]=suf5[i+1];
            }
            if(s[i]-'0'==0){
                suf0[i]=i;
                ans=n-1;
            }else if(s[i]-'0'==5){
                suf5[i]=i;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0' && (i+1<n && suf0[i+1]!=-1)){
                ans=min(ans,n-2-i);
            } 
            if(s[i]=='2' && (i+1<n && suf5[i+1]!=-1)){
                ans=min(ans,n-2-i);
            } 
            if(s[i]=='5' && (i+1<n && suf0[i+1]!=-1)){
                ans=min(ans,n-2-i);
            } 
            if(s[i]=='7' && (i+1<n && suf5[i+1]!=-1)){
                ans=min(ans,n-2-i);
            } 
        }
        return ans;
    }
};