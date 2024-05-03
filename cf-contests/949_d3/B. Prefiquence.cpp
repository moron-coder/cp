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
    ll n,m;
    cin>>n>>m;
    string sn,sm;
    cin>>sn>>sm;

    ll i=0;
    string ans;
    for(ll j=0;j<sm.size();j++){
        if(sm[j]==sn[i]){
            ans.push_back(sn[i]);
            i++;
        }
    }

    cout<<ans.size()<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}