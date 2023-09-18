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
    bool ok(unordered_map<int,vector<int>> &elToPos,int mid,int k){
        for(auto it:elToPos){
            int n=it.second.size();
            if(it.second.size()>=mid){
                for(int i=0;i+mid-1<n;i++){
                    int tot = it.second[i+mid-1]-it.second[i]+1, taken = mid, del = tot-taken;
                    if(del<=k) return true;
                }
            }
        }
        return false;
    }

    int longestEqualSubarray(vector<int>& ar, int k) {
        unordered_map<int,vector<int>> elToPos;
        int n=ar.size();
        for(int i=0;i<n;i++) elToPos[ar[i]].push_back(i);
        int hi=n,lo=0,ans=lo;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(ok(elToPos,mid,k)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};