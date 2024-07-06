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

/**
* @author : Utkarsh Kumar
* @date : 2024-07-06
*/

class Solution {
    int calcMinAr(vector<vector<int>>& ar,int r1,int c1,int r2,int c2){
        int rmin=31,cmin=31,rmax=-1,cmax=-1;
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                if(ar[i][j]){
                    rmin=min(rmin,i);
                    rmax=max(rmax,i);
                    cmin=min(cmin,j);
                    cmax=max(cmax,j);
                }
            }
        }
        return (rmax-rmin+1)*(cmax-cmin+1);
    }

    int help(vector<vector<int>>& ar,int r1,int c1,int r2,int c2,int cuts){
        if(!cuts){
            return calcMinAr(ar,r1,c1,r2,c2);
        }
        int ans=INT_MAX;
        for(int i=r1;i<r2;i++){
            int a1 = help(ar,r1,c1,i,c2,0) + help(ar,i+1,c1,r2,c2,cuts-1);      //  place rectangle in the above region
            int a2 = help(ar,r1,c1,i,c2,cuts-1) + help(ar,i+1,c1,r2,c2,0);      //  place rectangle in the below region
            ans=min({ans,a1,a2});
        }
        for(int j=c1;j<c2;j++){
            int a1 = help(ar,r1,c1,r2,j,0) + help(ar,r1,j+1,r2,c2,cuts-1);      //  place rectangle in the left region
            int a2 = help(ar,r1,c1,r2,j,cuts-1) + help(ar,r1,j+1,r2,c2,0);      //  place rectangle in the right region
            ans=min({ans,a1,a2});
        }
        return ans;
    }
public:
    int minimumSum(vector<vector<int>>& ar) {
        if(ar.size()==0){
            return -1;
        }
        return help(ar,0,0,ar.size()-1,ar[0].size()-1,2);   
    }
};