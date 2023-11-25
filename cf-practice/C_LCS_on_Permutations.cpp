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
    vector<ll> v1(n,-1),v2(n,-1);
    for(ll i=0;i<n;i++) cin>>v1[i];
    for(ll i=0;i<n;i++) cin>>v2[i];

    unordered_map<ll,ll> mp;                //  values of 1st map's elements to their index
    for(ll i=0;i<n;i++) mp[v1[i]]=i;        
    vector<ll> arLIS;
    for(ll i=0;i<v2.size();i++) arLIS.push_back(mp[v2[i]]);

    vector<ll> lis;
    for(ll i=0;i<arLIS.size();i++){
        ll pos = upper_bound(lis.begin(),lis.end(),arLIS[i])-lis.begin();
        if(pos==lis.size()){
            // all elements are <=
            lis.push_back(arLIS[i]);
        }else{
            lis[pos] = arLIS[i];
        }
    }
    cout<<lis.size()<<endl;
}

int main(){
    ll t=1;
    // cin>>t;
    while (t--){
        solve();
    }
}