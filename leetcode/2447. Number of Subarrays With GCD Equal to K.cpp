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
    int getGCD(int x,int y){
        if(x>y) swap(x,y);
        if(y%x==0) return x;
        return getGCD(y%x,x);
    }

    int subarrayGCD(vector<int>& ar, int k) {
        int n=ar.size(),ans=0;
        for(int i=0;i<n;i++){
            int cur=ar[i];
            for(int j=i;j<n;j++){
                if(getGCD(cur,ar[j])==k) {
                    ans++;
                }
                cur=getGCD(cur,ar[j]);
            }
        }
        return ans;
    }
};