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

ll func(vector<ll> &ar,ll mn){
    ll ans=0;
    for(auto it:ar){
        ll tmp=it-mn;
        ans+=tmp/5,tmp%=5;
        ans+=tmp/2,tmp%=2;
        ans+=tmp/1,tmp%=1;
    }
    return ans;
}

void solve() {
    ll n,mn=1000;
    cin>>n;
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++){
        cin>>ar[i];
        mn=min(mn,ar[i]);
    }
    cout<<min({func(ar,mn),func(ar,mn-1),func(ar,mn-2)})<<endl;
}

int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
