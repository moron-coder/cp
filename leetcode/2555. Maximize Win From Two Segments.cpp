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
    int maximizeWin(vector<int>& ar, int k) {
        int ans=0,n=ar.size();
        vector<int> suf(n,1);
        for(int i=n-1;i>=0;i--){
            int pos=upper_bound(ar.begin()+i,ar.end(),ar[i]+k)-ar.begin()-1;
            suf[i]=pos-i+1;
            int curAns=pos-i+1;
            if(pos+1<n) curAns+=suf[pos+1];
            ans=max(ans,curAns);
            if(i+1<n) suf[i]=max(suf[i],suf[i+1]);
        }
        return ans;
    }
};