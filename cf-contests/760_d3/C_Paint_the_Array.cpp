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

ll getGcd(vector<ll> &ar,ll st){
    ll n=ar.size(),cur=ar[st];
    for(ll i=st;i<n;i+=2) cur=__gcd(cur,ar[i]);         //  O(log(ar[i]));
    return cur;
}

void solve(){
    ll n;
    cin>>n;
    vector<set<ll>> v(n);
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    // let g1 = gcd of ar[0],ar[2],ar[4],ar[6],..
    // if any of ar[1],ar[3],ar[5],.. is divisible by g1, then g1 cant be our ans
    // else g1 is our ans
    ll g1=getGcd(ar,0),g2=getGcd(ar,1);
    bool ok1=true,ok2=true;
    for(ll i=1;i<n && ok1;i+=2){
        if(ar[i]%g1) continue;
        ok1=false;
    }
    if(ok1){
        cout<<g1<<endl;
        return;
    }
    for(ll i=0;i<n && ok2;i+=2){
        if(ar[i]%g2) continue;
        ok2=false;
    }
    if(ok2){
        cout<<g2<<endl;
        return;
    }
    cout<<0<<endl;
}

int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}