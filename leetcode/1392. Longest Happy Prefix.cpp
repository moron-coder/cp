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
    int getJ(vector<int> &pi,int i,int j,string &s){
        if(s[j]==s[i]){
            return j;           //  if s[j] matches s[i], pi[i] = pi[i-1]+1
        }
        if(j==0) return -1;
        return getJ(pi,i,pi[j-1],s);
    }
public:
    string longestPrefix(string s) {
        int n=s.size(),ans=0;
        vector<int> pi(n,0);
        for(int i=1;i<n;i++){ 
            int j = getJ(pi,i,pi[i-1],s);
            pi[i] = j+1;
        }
        return s.substr(0,pi.back());
    }
};