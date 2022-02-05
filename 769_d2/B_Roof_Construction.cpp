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
    ll n,lim=1;
    cin>>n;
    while ((lim<<1)<=(n-1)) lim=(lim<<1);
    for(ll i=n-1;i>=lim;i--) cout<<i<<" ";
    for(ll i=0;i<lim;i++) cout<<i<<" ";
    cout<<endl;
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
