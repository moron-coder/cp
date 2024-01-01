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
    bool isOk(vector<vector<int>> fq,int mid){
        for(auto it:fq){
            int ct=0;
            for(auto count:it){
                ct+=max(0,(count-1)-(mid-1)+1);
            }
            if(ct>=3){
                return true;
            }
        }
        return false;
    }

    int maximumLength(string s) {
        char prev=s[0];
        int ct=0;
        vector<vector<int>> fq(26,vector<int>());
        for(auto it:s){
            if(it==prev){
                ct++;
            }else{
                fq[prev-'a'].push_back(ct);
                prev=it;
                ct=1;
            }
        }
        fq[prev-'a'].push_back(ct);
        for(auto &it:fq){
            sort(it.begin(),it.end());
        }
        int lo=1,hi=s.size(),ans=-1;
        while (lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isOk(fq,mid)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};