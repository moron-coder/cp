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

class Solution
{
    public:
    bool search(vector<vector<int> > ar, int n, int m, int x){
        int i=0,j=m-1;
        while(i<n && j<m && i>=0 && j>=0){
            if(ar[i][j]==x) return true;
            else if(ar[i][j]>x){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};