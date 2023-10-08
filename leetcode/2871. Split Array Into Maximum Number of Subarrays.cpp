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
    int maxSubarrays(vector<int>& ar) {
        int cur=ar[0],ans=0,n=ar.size(),minPossibleScore = ar[0];
        vector<int> pre(n,ar[0]);
        for(int i=1;i<n;i++){
            pre[i]=(ar[i]&pre[i-1]);
            minPossibleScore = (minPossibleScore&ar[i]);
        }
        bool gotMinPossibleScore=false;
        for(int i=0;i<n;i++){
            cur=(cur&ar[i]);
            if(!gotMinPossibleScore){
                if(cur==minPossibleScore){
                    gotMinPossibleScore = true;
                    ans++;
                    if(i+1<n) cur=ar[i+1];
                }
            }else{
                if(cur==0){
                    ans++;
                    if(i+1<n) cur=ar[i+1];
                }
            }
        }
        return ans;
    }
};

