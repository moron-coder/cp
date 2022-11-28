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
    int bestClosingTime(string s) {
        int n=s.size(),ans=0,minLoss=INT_MAX;
        vector<int> pre(n,s[0]=='N'),suf(n,s.back()=='Y');
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+(s[i]=='N');
        for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+(s[i]=='Y');
        minLoss=suf[0];
        // pre[i] : loss till 'i' if shop is open till (including) 'i'
        // suf[i] : loss from 'i' if shop is closed at 'i'
        //debug
        cout<<"pre\n";
        for(auto it:pre) cout<<it<<" ";
        cout<<endl;
        cout<<"suf\n";
        for(auto it:suf) cout<<it<<" ";
        cout<<endl;
        //debug
        for(int i=0;i<n-1;i++){
            if(pre[i]+suf[i+1]<minLoss){
                minLoss=pre[i]+suf[i+1];
                ans=i+1;
            }
        }
        if(pre[n-1]<minLoss) ans=n;
        return ans;
    }
};