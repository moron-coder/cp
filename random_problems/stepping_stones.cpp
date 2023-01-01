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

ll dpmx[2][1000001],dpmn[2][1000001];

ll getMax(vector<ll> &ar,ll pos,ll m,bool isHere){
    int n=ar.size();
    if(pos>=n) return 0;
    if(dpmx[isHere][pos]!=-1) return dpmx[isHere][pos];
    ll cur=0;
    if(isHere){
        cur=ar[pos]+max(getMax(ar,pos+m+1,m,true),getMax(ar,pos+m,m,false));
    }else{
        cur=max(getMax(ar,pos+1,m,true),getMax(ar,pos+1,m,false));
    }
    return dpmx[isHere][pos]=cur;
}

ll getMin(vector<ll> &ar,ll pos,ll m,bool isHere){
    int n=ar.size();
    if(pos>=n) return 0;
    if(dpmn[isHere][pos]!=-1) return dpmn[isHere][pos];
    ll cur=0;
    if(isHere){
        cur=ar[pos]+min(getMin(ar,pos+m+1,m,true),getMin(ar,pos+m,m,false));
    }else{
        cur=min(getMin(ar,pos+1,m,true),getMin(ar,pos+1,m,false));
    }
    return dpmn[isHere][pos]=cur;
}

void solve() {
    ll n,m;
    cin>>n;
    vector<ll> ar(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    cin>>m;
    memset(dpmx,-1,sizeof(dpmx));
    memset(dpmn,-1,sizeof(dpmn));
    ll mx=max(getMax(ar,0,m,true),getMax(ar,0,m,false));
    // cout<<"mx= "<<mx<<endl;
    ll mn=min(getMin(ar,0,m,true),getMin(ar,0,m,false));
    // cout<<"mn= "<<mn<<endl;
    cout<<mx-mn<<endl;
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
    return 0;
}