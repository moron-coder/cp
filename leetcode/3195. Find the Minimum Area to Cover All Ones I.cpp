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
* @date : 2024-06-30
*/

class Solution {
public:
    int minimumArea(vector<vector<int>>& ar) {
        int i1=ar.size(),j1=ar[0].size(),i2=-1,j2=-1;
        for(int i=0;i<ar.size();i++){
            for(int j=0;j<ar[i].size();j++){
                if(ar[i][j]){
                    i1=min(i1,i);
                    j1=min(j1,j);
                    i2=max(i2,i);
                    j2=max(j2,j);
                }
            }
        }
        return (i2-i1+1)*(j2-j1+1);
    }
};