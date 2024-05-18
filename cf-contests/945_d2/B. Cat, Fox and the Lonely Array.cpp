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

void excludeBits(ll &bitOr, vector<ll> &arOr,int numToExclude){
    for(int i=0;i<31;i++){
        bool wasSet= (arOr[i]!=0);
        if(numToExclude&(1<<i)){
            arOr[i]--;
        }
        if(wasSet && arOr[i]==0){
            bitOr^=(1<<i);
        }
    }
}

void includeBits(ll &bitOr, vector<ll> &arOr,int numToInclude){
    for(int i=0;i<31;i++){
        bool wasUnset= (arOr[i]==0);
        if(numToInclude&(1<<i)){
            arOr[i]++;
        }
        if(wasUnset && arOr[i]!=0){
            bitOr^=(1<<i);
        }
    }
}

bool ok(vector<ll> &ar,ll len){
    ll bitOr=0,iniBit=-1;
    vector<ll> arOr(32,0);
    for(ll i=0;i<ar.size();i++){
        includeBits(bitOr,arOr,ar[i]);
        if(i-len>=0){
            excludeBits(bitOr,arOr,ar[i-len]);
        }
        if(i<len-1){
            continue;
        }
        if(iniBit!=-1 && iniBit!=bitOr){
            return false;
        }
        iniBit=bitOr;
    }
    return true;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> ar(n,-1);
    for(int i=0;i<n;i++) cin>>ar[i];
    ll lo=1,hi=n,ans=n;

    while (lo<=hi){
        ll mid = lo+(hi-lo)/2;
        if(ok(ar,mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}