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
    bool isOk(vector<int> &ar,int k,ll mid){
        for(int i=0,ct=0;i<ar.size();i++){
            if(ar[i]<=mid){
                ct++,i++;
            }
            if(ct>=k) return true;
        }
        return false;
    }

    int minCapability(vector<int>& ar, int k) {
        ll ans=INT_MAX,lo=0,hi=10000000000;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isOk(ar,k,mid)){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;
    }
};