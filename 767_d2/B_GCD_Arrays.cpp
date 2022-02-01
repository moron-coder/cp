#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define ll long long int

void solve() {
    ll lf,rt,k;
    cin>>lf>>rt>>k;
    if(lf==rt){
        if(lf==1) cout<<"NO\n";
        else cout<<"YES\n";
        return;
    }
    ll tots=rt-lf+1,ods=0,evs=0;
    if(tots%2==0) ods=tots/2,evs=ods;
    else{
        if(lf%2) ods=(tots+1)/2,evs=tots/2;
        else evs=(tots+1)/2,ods=tots/2;
    }
    // cout<<evs<<" "<<ods<<endl;
    if(k>=ods){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
