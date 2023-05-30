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
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    sort(ar.begin(),ar.end());
    vector<ll> ans;
    ll i=0,j=n-1;
    while (i<=j){
        ans.push_back(ar[j]);
        j--;
        if(i>j) break;
        ans.push_back(ar[i]);
        i++;
    }
    // cout<<"ans:\n";
    // for(auto it:ans) cout<<it<<" ";
    // cout<<endl;
    vector<ll> pSum(n,ans[0]);
    for(ll i=1;i<n;i++){
        pSum[i]=pSum[i-1]+ans[i];
        if(pSum[i-1]==ans[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}

int main(){
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}