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
    pair<bool,int> countIsOkAndNumBit(int n){
        int ct=0,init=n;
        bool isOk=true;
        while (n){
            if(!(n&1)) isOk=false;
            ct++;
            n/=2;
        }
        return {isOk,ct};
    }

    int racecar(int n) {
        int *dp=new int[n+1]();
        for(int i=1;i<=n;i++){
            pair<bool,int> pbi = countIsOkAndNumBit(i);
            if(pbi.first) dp[i]=pbi.second;
            else{
                dp[i]=INT_MAX;
                int lo=(1<<(pbi.second-1))-1,hi=(1<<pbi.second)-1;
                for(int tmp=0;(lo-((1<<tmp)-1))>=0;tmp++){
                    dp[i]=min({dp[i],pbi.second+1+dp[hi-i],pbi.second-1+1+tmp+1+dp[i-lo+((1<<tmp)-1)]});
                }
            }
        }
        return dp[n];
    }
};