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
    void help(int openCt,int closedCt,int &n,vector<string> &ans,string &cur){
        if(closedCt==n){
            ans.push_back(cur);
            return;
        }
        if(openCt>closedCt){
            cur.push_back(')');
            help(openCt,closedCt+1,n,ans,cur);
            cur.pop_back();     //  backtrack
        }
        if(openCt+1<=n){
            cur.push_back('(');
            help(openCt+1,closedCt,n,ans,cur);
            cur.pop_back();         //  backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curStr;
        help(0,0,n,ans,curStr);
        return ans;
    }
};