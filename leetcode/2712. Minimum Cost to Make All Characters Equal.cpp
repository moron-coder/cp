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
    long long makeDig(string &s){
        long long n=s.size(),costMin=LONG_MAX,sumFromLastChange = 0;
        vector<long long> pre(n,0),suf(n,0);
        for(int i=0;i<n;i++){
            if(i && s[i]!=s[i-1]){
                sumFromLastChange+=i;
            }
            if(s[i]-'0'==1){
                pre[i]=(i+1)+sumFromLastChange;   
            }else{
                pre[i]=(i)?pre[i-1]:0;
            }
        }
        sumFromLastChange=0;
        for(int i=n-1;i>=0;i--){
            if(i+1<n && s[i]!=s[i+1]){
                sumFromLastChange+=n-i-1;
            }
            if(s[i]-'0'==1){
                suf[i]=(n-i)+sumFromLastChange;
            }else{
                suf[i]=(i+1<n)?suf[i+1]:0;
            }
        }
        for(int i=0;i<n-1;i++){
            costMin=min(costMin,pre[i]+suf[i+1]);
        }
        return (costMin==LONG_MAX)?0:costMin;
    }

    long long minimumCost(string s) {
        string sInv = s,s1=s;
        reverse(s1.begin(),s1.end());
        for(auto &it:sInv){
            if(it=='0') it='1';
            else it='0';
        }
        string s2=sInv;
        reverse(s2.begin(),s2.end());
        return min({makeDig(s),makeDig(sInv),makeDig(s1),makeDig(s2)});
    }
};