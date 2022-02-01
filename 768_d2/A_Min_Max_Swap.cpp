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
    ll n;
    cin>>n;
    vector<ll> a(n,-1),b(n,-1);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++){
        cin>>b[i];
        if(b[i]<a[i]) swap(a[i],b[i]);
    }
    ll maxA=a[0],maxB=b[0];
    for(auto it:a) maxA=max(maxA,it);
    for(auto it:b) maxB=max(maxB,it);
    cout<<maxA*maxB<<endl;
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
