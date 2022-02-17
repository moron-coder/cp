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

void solve() {
    ll n;
    cin>>n;
    vector<ll> ar(n,-1),sortedAr(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    for(ll i=0;i<n;i++) sortedAr[i]=ar[i];
    sort(sortedAr.begin(),sortedAr.end());
    for(ll i=0;i<n;i++){
        if(sortedAr[i]!=ar[i]){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    // I want index i such that ar[i]>ar[i+1]
    // sort ar[0]~ar[i] and ar[i+1]~ar[n-1]
    // if the array is not already sorted, then yes, else no
}

int main() {
    ll t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}
