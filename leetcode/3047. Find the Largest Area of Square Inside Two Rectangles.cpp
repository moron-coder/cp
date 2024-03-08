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

class rect{
    public:

    int yu,yd,xl,xr;

    rect(int yu,int yd,int xl,int xr){
        this->yu=yu;
        this->yd=yd;
        this->xl=xl;
        this->xr=xr;
    }

    

    long long maxIntersection(rect r){
        int newXl = max(this->xl,r.xl);
        int newYd = max(this->yd,r.yd);
        int newXr = min(this->xr,r.xr);
        int newYu = min(this->yu,r.yu);
        
        return max(0,min(newYu-newYd,newXr-newXl));
        
    }
};

class Solution {
    
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        vector<rect> v;
        long long ans=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            v.push_back(rect(topRight[i][1],bottomLeft[i][1],bottomLeft[i][0],topRight[i][0]));
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    ans=max(ans,v[i].maxIntersection(v[j]));
                }
            }
        }
        return ans*ans;
    }
};