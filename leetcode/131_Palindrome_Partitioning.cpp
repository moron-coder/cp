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

static int ctr;

class Solution {
public:
    vector<vector<string>> ans;

    bool isPal(string &s){
        int j=s.size()-1,i=0;
        while (i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
            // ctr++;                      //  isPal
        }
        return true;
    }

    void help(string &s,int pos,vector<string> &cur){
        ctr++;                          //  help ctr
        int n=s.size();
        if(pos>=n){
            ans.push_back(cur);
            return;
        }
        for(int i=pos;i<n;i++){
            string sm=s.substr(pos,i-pos+1);
            // ctr+=i-pos+1;               //  subStr
            if(isPal(sm)){
                cur.push_back(sm);
                // ctr+=sm.size();         //  push
                help(s,i+1,cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        ctr=0;
        ans.clear();
        vector<string> cur;
        help(s,0,cur);
        cout<<ctr<<" operations\n";
        return ans;
    }
};
