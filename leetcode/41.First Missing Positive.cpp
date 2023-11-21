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

class Solution{
    public:
    const static int MAX_INT = 1000000;

    int firstMissingPositive(vector<int> &ar){
        int n=ar.size();
        for(int i=0;i<n;i++) if(ar[i]<=0 || ar[i]>n) ar[i] = MAX_INT;
        for(int i=0;i<n;i++){
            if(abs(ar[i]-1)<n){
                ar[abs(ar[i]-1)]=-1*abs(ar[abs(ar[i]-1)]);
            }
        }
        for(int i=0;i<n;i++){
            if(ar[i]>0) return i+1;
        }
        return n+1;
    }
}; 