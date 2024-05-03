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
    vector<ll> ar(n,-1),ar2(n,-1);
    ll mx=-1,posMx=-1;
    for(ll i=0;i<n-1;i++){
        cin>>ar[i];
        ar2[i]=ar[i]+1;
    }
    for(int i=1;i<n;i++){
        // ar2[i] = ar2[i-1]+ar[i-1];
        ll cur=ar2[i-1],mlt=2;
        while (cur<=ar2[i]){
            cur*=mlt;
            mlt++;
        }
        cur+=ar[i-1];
        ar2[i]=cur;
    }
    for(auto it:ar2) cout<<it<<" ";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}