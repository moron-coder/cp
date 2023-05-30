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

ll rec(vector<ll> &ar,ll pos){
    if(pos<0) return 0;
    ll n=ar.size();
    for(ll i=pos;i>=0;i--){
        if(ar[i]!=ar.back()){
            // ar[i+1]~ar.back() are same
            ll len=(n-1)-(i+1)+1;         //  =pos-i
            ll nextPos=i-len;
            return 1+rec(ar,nextPos);
        }
    }
    return 0;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    cout<<rec(ar,n-1)<<endl;
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
