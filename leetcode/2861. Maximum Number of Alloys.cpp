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
    const static long long MAX_ANS = 100000000000;
public:
    bool isOk(int mid,long long budget,vector<int> &composition,vector<int> &stock,vector<int> &cost){
        long long n=stock.size(),totCost=0;
        for(int i=0;i<n;i++){
            long long unitsReq = 1LL*mid*composition[i]-stock[i];
            totCost+= 1LL*max(0LL,unitsReq)*cost[i]; 
        }
        return totCost<=budget;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long hi=MAX_ANS,lo=0,ans=0;
        while (lo<=hi){
            long long mid=lo+(hi-lo)/2;
            bool ok=false;
            for(int i=0;i<composition.size() && !ok;i++){
                if(isOk(mid,budget,composition[i],stock,cost)){
                    ok=true;
                }
            }
            if(ok){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans;
    }
};