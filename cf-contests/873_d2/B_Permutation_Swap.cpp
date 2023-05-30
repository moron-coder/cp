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
    vector<ll> deltas;
    for(ll i=0;i<n;i++){
        cin>>ar[i];
        ar[i]--;
        if(ar[i]!=i) deltas.push_back(abs(i-ar[i]));
    }
    sort(deltas.begin(),deltas.end());
    ll prev=-1,ans=1;
    for(auto it:deltas){
        if(prev!=-1) ans=__gcd(ans,prev);
        else ans=it;
        prev=it;
    }
    cout<<ans<<endl;
}

int main(){
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}