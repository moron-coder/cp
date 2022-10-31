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
    long long checkCost(vector<int> &ar,vector<int> &cost,long long th){
        ll curCost=0;
        for(int i=0;i<ar.size();i++) curCost+=(abs(th-ar[i])*cost[i]);
        return curCost;
    }

    long long minCost(vector<int>& ar, vector<int>& cost) {
        long long ans=LONG_MAX,hi=ar[0],lo=ar[0];
        for(ll it:ar) hi=max(hi,it),lo=min(lo,it);
        while (lo<=hi){
            ll mid=lo+(hi-lo)/2,cl=checkCost(ar,cost,mid-1),cm=checkCost(ar,cost,mid),ch=checkCost(ar,cost,mid+1);
            ans=min({ans,cl,cm,ch});
            if(cm<min(cl,ch)){
                // got minima
                return cm;
            }else if(cm<ch){
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;      //  not possible
    }
};