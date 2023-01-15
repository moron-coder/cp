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
    int minTaps(int n, vector<int>& ar) {
        for(int i=0;i<=n;i++){
            ar[max(0,i-ar[i])]=max(ar[max(0,i-ar[i])],min(n,i+ar[i]));
        }
        // for(int i=0;i<=n;i++) cout<<ar[i]<<" ";
        // cout<<endl;
        int mxr=-1,ans=0,cur=0;
        for(int i=0;i<=n;i++){
            mxr=max(mxr,ar[i]);
            if(i==cur){
                if(i==n) return ans;
                ans++;
                cur=mxr;
            }else if(i>cur){
                // cout<<i<<" ret\n";
                return -1;
            }
        }
        return ans;
    }
};