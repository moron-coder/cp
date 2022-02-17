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

ll dp[101][10001];

void solve() {
    memset(dp,-1,sizeof(dp));
    ll n,sum=0,cur=INT_MAX,ai2=0,bi2=0;
    cin>>n;
    vector<ll> ar1(n,-1),ar2(n,-1);
    for(ll i=0;i<n;i++) cin>>ar1[i];
    for(ll i=0;i<n;i++) cin>>ar2[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    for(auto it:ar1) sum+=it,ai2+=it*it;
    for(auto it:ar2) sum+=it,bi2+=it*it;
    dp[0][ar1[0]]=1;
    dp[0][ar2[0]]=1;
    for(ll i=0;i<n-1;i++){
        for(ll j=0;j<=10000;j++){
            if(dp[i][j]==1){
                dp[i+1][j+ar1[i+1]]=1;
                dp[i+1][j+ar2[i+1]]=1;
            }
        }
    }
    for(ll j=0;j<=10000;j++) if(dp[n-1][j]==1) cur=min(cur,j*j+(sum-j)*(sum-j));
    ll ans=(n-2)*(ai2+bi2)+cur;
    cout<<ans<<endl;
}

int main() {
    ll t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}
/*
7+8+9+8+1+7+88+75+69+82+75+90
*/