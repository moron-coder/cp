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
    // int rec(vector<int> &ar,int pos){
    //     int n=ar.size();
    //     if(pos>=n) return 1;
        
    // }

    int numberOfGoodSubarraySplits(vector<int>& ar) {
        long long int n=ar.size(),ans=1,lastOne=-1;
        for(int i=0;i<ar.size();i++){
            if(ar[i]){
                if(lastOne!=-1) ans=(ans*(i-lastOne))%mod;
                lastOne=i; 
            }
        }
        return (lastOne==-1)?0:ans;
    }
};