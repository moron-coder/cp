#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<long, long>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define ll long long int

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n,-1);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll mx=v[0],mn=v[0];
    for(auto it:v){
        mx=max(mx,it);
        mn=min(mn,it);
    }
    cout<<mx-mn<<endl;
}

int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}