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
    ll n,k,ans=0;
    cin>>n>>k;
    vector<ll> v(n,-1);
    for(ll i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(ll i=0;i<k;i++) ans+=(v[n-1-i-k]/v[n-1-i]);
    // n-1-(k-1)-k = n-2*k
    for(ll i=n-2*k-1;i>=0;i--) ans+=v[i];
    cout<<ans<<endl;
}

int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}