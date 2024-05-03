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

void solve(){
    ll x,ans=-1;
    cin>>x;
    ll mx=INT_MIN;
    for(ll y=1;y<x;y++){
        if(__gcd(x,y)+y>mx){
            mx=__gcd(x,y)+y;
            ans=y;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}