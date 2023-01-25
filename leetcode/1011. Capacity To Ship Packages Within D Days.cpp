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
    bool isOk(vector<int> &weights,int days,int cap){
        int sum=0,cur=1;
        for(auto it:weights){
            if(it>cap) return false;
            sum+=it;
            if(sum>cap){
                sum=it;
                cur++;
            }
        }
        return cur<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int lo=0,hi=INT_MAX,ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isOk(weights,days,mid)){
                hi=mid-1;
                ans=mid;
            }else lo=mid+1;
        }
        return ans;
    }
};