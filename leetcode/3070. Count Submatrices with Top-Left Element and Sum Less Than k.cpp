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
    int countSubmatrices(vector<vector<int>>& ar, int k) {
        int n=ar.size(),m=ar[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                if(i) sum+=ar[i-1][j];
                if(j) sum+=ar[i][j-1];
                if(i && j) sum-=ar[i-1][j-1];
                ar[i][j]=sum+ar[i][j];
                ans+=(ar[i][j]<=k);
            }
        }
        //debug
        for(auto it:ar){
            for(auto it1:it) cout<<it1<<" ";
            cout<<endl;
        }
        //debug
        return ans;
    }
};