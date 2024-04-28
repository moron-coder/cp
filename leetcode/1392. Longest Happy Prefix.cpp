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
    string longestPrefix(string s) {
        int n=s.size(),ans=0;
        vector<int> pi(n,0);
        for(int i=1;i<n;i++){ 
            int j=pi[i-1];
            while (1){
                if(s[j]==s[i]){
                    break;
                }
                if(j==0){
                    j=-1;
                    break;
                }
                j=pi[j-1];
            }
            pi[i] = j+1;
        }
        return s.substr(0,pi.back());
    }
};