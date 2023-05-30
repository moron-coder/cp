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
    bool ans=true;
    cin>>n;
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    // taking the highest nos greedily
    bool *used=new bool[n]();
    for(ll i=0;i<n;i++){
        while (ar[i]>n || used[ar[i]-1]){
            ar[i]/=2;
            if(!ar[i]) break;
        }
        if(ar[i]) used[ar[i]-1]=true;
    }
    for(ll i=0;i<n && ans;i++) if(!used[i]) ans=false;
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}