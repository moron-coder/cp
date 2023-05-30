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
    vector<ll> v(7,-1);
    for(int i=0;i<7;i++) cin>>v[i];
    cout<<v[0]<<" "<<v[1]<<" "<<v[6]-v[0]-v[1]<<endl;
}

int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}