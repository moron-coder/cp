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

bool ok(vector<ll> &ar,ll mid){
    ll sum=mid;
    for(auto it:ar){
        if(2LL*sum<it) return false;
        sum=2LL*sum-it;
        if(sum>10000000000) return true;
    }
    return true;    
}

void solve() {
    ll n,lo=0,hi=10000000000,ans=10000000000;
    cin>>n;
    vector<ll> ar(n,0);
    for(ll i=0;i<n;i++) cin>>ar[i];
    while (lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(ok(ar,mid)){
            ans=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    cout<<ans<<endl;
}

int main() {
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
