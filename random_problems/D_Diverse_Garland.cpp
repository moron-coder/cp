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

void rec(vector<pii> &v,string &s,ll pos){
    if(pos>=s.size()) return;
    ll i=pos;
    for(;i<s.size() && s[i]==s[pos];i++);
    v.push_back({i-pos,(s[pos]=='R')?0:(s[pos]=='G')?1:2});
    rec(v,s,i);
}

ll ch;

void make(vector<pii> &v,ll vPos,vector<ll> &ans,ll ansPos){
    if(vPos>=v.size()) return;
    int ct=v[vPos].first/2,idx=ansPos+v[vPos].first%2,col=(v[vPos].first%2==0 && vPos)?3-v[vPos].second-v[vPos-1].second:(v[vPos].second+1)%3;
    for(ll i=0;i<ct;i++){
        ans[idx]=col;
        idx+=2,ch++;
    }
    make(v,vPos+1,ans,idx);
}

void solve(){
    ch=0;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<pii> v;              //  contains {len,color}
    rec(v,s,0);
    vector<ll> ans(n,-1);
    for(ll i=0;i<n;i++) ans[i]=((s[i]=='R')?0:(s[i]=='G')?1:2);
    make(v,0,ans,0);
    cout<<ch<<endl;
    for(auto it:ans){
        if(it==0) cout<<'R';
        if(it==1) cout<<'G';
        if(it==2) cout<<'B';
    }
    cout<<endl;
}

int main() {
    ll t=1;
    // cin>>t;
    while (t--) solve();    
    return 0;
}