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

void solve() {
    ll n,oneCt=0,ans=0;
    cin>>n;
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    for(ll i=1;i<n-1;i++) oneCt+=(ar[i]==1);
    if(n==3 && ar[1]%2){
        cout<<-1<<endl;
        return;
    }
    if(oneCt==n-2){
        cout<<-1<<endl;
        return;
    }
    for(ll i=1;i<n-1;i++) ans=(ans+(ar[i]+1)/2);
    cout<<ans<<endl;
}

int main() {
    ll t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}
