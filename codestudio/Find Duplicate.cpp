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

int duplicateNumber(int *ar, int n){
    ll s1=0,s1_exp=(1LL*n*(n+1))/2,s2=0,s2_exp=(1LL*n*(n+1)*(2*n+1))/6;
    for(ll i=0;i<n;i++){
        s1+=ar[i]+1;                    //  0 indexed by default
        s2+=(ar[i]+1)*(ar[i]+1);        //  0 indexed by default
    }
    ll yPx = (s2-s2_exp)/(s1-s1_exp);
    ll yMx = s1-s1_exp;
    ll y=(yPx+yMx)/2;
    return y;
}