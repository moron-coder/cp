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
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++){
        cin>>ar[i];
    }
    vector<ll> idx(n,-1);
    for(ll i=0;i<n;i++) idx[ar[i]-1]=i;
    ll mx=INT_MAX,ans=0;
    for(auto it:idx){
        if(mx>it){
            mx=it;
            ans++;
        }
        mx=max(mx,it);
    }
    cout<<ans<<endl;
}

int main(){
    ll t=1;
    // cin>>t;
    while (t--){
        solve();
    }
    return 0;
}