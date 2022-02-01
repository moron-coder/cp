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

ll rec(ll st,ll p,ll k,vector<ll> &ar){
    if(st+k-1<ar.size() && ar[st+k-1]<=p) return k+rec(st+k,p-ar[st+k-1],k,ar);
    return 0;
}

void solve(){
    ll n,p,k,i=k-1,ans=0,sum=0;
    cin>>n>>p>>k;
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    sort(ar.begin(),ar.end());
    ans=rec(0,p,k,ar);
    for(ll i=0;i<k && sum<p;i++){
        sum+=ar[i];
        if(sum>p) break;
        ans=max(ans,i+1+rec(i+1,p-sum,k,ar));
    }
    cout<<ans<<endl;
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}