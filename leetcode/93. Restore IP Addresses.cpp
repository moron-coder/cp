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
    vector<string> gAns;

    void help(string &s, int pos,int blk,string &sm){
        int n=s.size(),cur=0;
        if(pos>=n){
            if(blk==4){
                sm.pop_back();          //  remove last '.'
                gAns.push_back(sm);
                sm.push_back('.');
            }
            return;
        }
        if(blk>=4) return;
        for(int i=pos;i<n;i++){
            if(s[pos]=='0' && i>pos){
                return;
            }
            cur=cur*10+(s[i]-'0');
            if(cur>255) break;
            sm+=to_string(cur);
            sm.push_back('.');
            help(s,i+1,blk+1,sm);
            sm.pop_back();          //  remove my '.'
            while (sm.size() && sm.back()!='.'){
                sm.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string sm;
        help(s,0,0,sm);
        return gAns;
    }
};

/*

["1.0.1.23","1.0.10.23","1.0.102.3","1.1.0.23","1.1.2.3","1.10.2.3","10.1.0.23","10.1.2.3","10.10.2.3","101.0.2.3"]

["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

*/