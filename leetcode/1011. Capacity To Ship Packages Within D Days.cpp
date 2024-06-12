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
    bool isOk(vector<int> &ar,int d,int cap){
        int sum=0,dayCt=0;
        for(int i=0;i<ar.size();i++){
            sum+=ar[i];
            if(sum>cap){
                dayCt++;
                sum=ar[i];
            }
        }
        return dayCt+1<=d;
    }
public:
    int shipWithinDays(vector<int>& ar, int d) {
        int lo=0,hi=25000000,ans=hi;
        for(auto it:ar) lo=max(lo,it);
        while (lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isOk(ar, d, mid)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};