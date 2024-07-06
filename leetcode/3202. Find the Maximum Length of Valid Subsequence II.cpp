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
* @date : 2024-07-05
*/

class Solution {
public:
    int maximumLength(vector<int>& ar, int k) {
        int n=ar.size(),ans=0;
        int **ctr=new int*[1001]();
        for(int i=0;i<=1000;i++){
            ctr[i] = new int[n]();
        }

        for(int i=0;i<n;i++){
            int maxLen=0;
            for(int j=0;j<i;j++){
                int rem = (ar[j]+ar[i])%k;
                ctr[rem][i] = max(ctr[rem][i], 1+ctr[rem][j]);
                ans=max(ans,ctr[rem][i]+1);
            }
        }
        return ans;
    }
};

