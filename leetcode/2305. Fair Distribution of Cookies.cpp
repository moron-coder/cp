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

    int help(vector<int> &ar,int pos,vector<int> &chocoCt,int used){
        int n=ar.size(),k = chocoCt.size(),ans=INT_MAX;
        if(pos>=n){
            ans = chocoCt[0];
            for(auto it:chocoCt) ans=max(ans,it);
            return ans;
        }
        for(int i=0;i<k;i++){
            chocoCt[i]+=ar[pos];
            int smallAns = help(ar,pos+1,chocoCt,used|(1<<i));
            chocoCt[i]-=ar[pos];
            ans=min(ans,smallAns);
        }
        return ans;
    }

    int distributeCookies(vector<int>& ar, int k) {
        vector<int> chocoCt(k,0);
        return help(ar,0,chocoCt,0);
    }
};