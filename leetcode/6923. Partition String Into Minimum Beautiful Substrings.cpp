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
    unordered_set<int> powersOfFive; 

    int help(string &s,int pos){
        int n=s.size();
        if(pos>=n) return 0;
        if(s[pos]=='0') return -1;
        int cur=0,ans=n+1;
        for(int i=pos;i<n;i++){
            cur=(cur<<1);
            cur+=s[i]-'0';
            if(powersOfFive.count(cur)){
                int small = help(s,i+1);
                if(small!=-1){
                    ans=min(ans,1+help(s,i+1));
                }
            }
        }
        return (ans==n+1)?-1:ans;
    }

    int minimumBeautifulSubstrings(string s) {
        powersOfFive.clear();
        int p=1;
        while (p<(1<<16)){
            powersOfFive.insert(p);
            p*=5;
        }
        return help(s,0);
    }
};