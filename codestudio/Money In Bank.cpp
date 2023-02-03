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

int totalMoney(int n){
    int t=(n-1)/7,x=(n-1)%7,ans=(7*(t*(t+1))/2+28*t+((x+1)*(x+2))/2);
    return ans;
}