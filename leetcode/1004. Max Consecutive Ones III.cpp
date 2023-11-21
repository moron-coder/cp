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
    bool isOk(vector<int> &pre,int len,int k){
        for(int i=0;i+len-1<pre.size();i++){
            int f1 = pre[i+len-1], f2 = i?pre[i-1]:0,cur = len-(f1-f2);
            if(cur<=k) return true;
        }
        return false;
    }

    int longestOnes(vector<int>& ar, int k) {
        int hi = ar.size(), lo=1, ans=0;
        for(int i=1;i<ar.size();i++) ar[i]+=ar[i-1];
        while (lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isOk(ar,mid,k)){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans;
    }
};