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


bool ok(ll rnk,vector<ll> preps,ll m){
    ll n=preps.size(),oppIdx=n-rnk,oppWins=oppIdx+1;
    // there are 2 ways to get rnk rank:
    //      1) Defeat 'oppWins' players whose preps<=m(remaining)
    //      2) Defeat 'oppWins-1' players whose preps<=m and defeat 'oppIdx' player
    vector<ll> rems;
    for(ll i=0;i<n;i++) if(i!=oppIdx) rems.push_back(preps[i]);
    sort(rems.begin(),rems.end());
    ll curSum=0,myWins=0;
    for(ll i=0;i<rems.size();i++){
        if(curSum+rems[i]<=m){
            curSum+=rems[i];
            myWins++;
        }else break;
    }
    if(myWins>=oppWins){
        // case 1
        return true;
    }
    // try case 2
    if(preps[oppIdx]>m){
        // case 2 not possible
        return false;
    }
    myWins=1;
    curSum=preps[oppIdx];
    for(ll i=0;i<rems.size();i++){
        if(curSum+rems[i]<=m){
            curSum+=rems[i];
            myWins++;
            if(myWins==oppWins-1) break;
        }
    }
    if(myWins>=oppWins-1){
        return true;
    }
    return false;
}

void solve() {
    ll n=0,m=0,tLoss=0,myWins=0,lo=1;
    cin>>n>>m;
    ll hi=n+1,ans=n+1;
    vector<ll> preps(n,-1);
    for(ll i=0;i<n;i++) cin>>preps[i];
    while (lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(ok(mid,preps,m)){
            ans=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    // cout<<"ans= "<<ans<<endl;
    cout<<ans<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}