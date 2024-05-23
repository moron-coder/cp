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
    ll n,sum=0;
    cin>>n;
    vector<ll> ar(n,-1);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar.begin(),ar.end());
    for(ll i=0;i<n;i++){
        if(sum+1<ar[i]){
            cout<<sum+1<<endl;
            return;
        }
        sum+=ar[i];
    }
    cout<<sum+1<<endl;
}

int main(){
    ll t=1;
    // cin>>t;
    while (t--){
        solve();
    }
    return 0;
}