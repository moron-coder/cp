#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define ll long long int

void solve() {
    ll n,ramSize;
    cin>>n>>ramSize;
    vector<pll> ar(n);
    for(ll i=0;i<n;i++) cin>>ar[i].first;
    for(ll i=0;i<n;i++) cin>>ar[i].second;
    sort(ar.begin(),ar.end());
    for(auto it:ar){
        if(it.first>ramSize) break;
        ramSize+=it.second;
    }
    cout<<ramSize<<endl;
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
