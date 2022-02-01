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
    ll a,b,c;
    cin>>a>>b>>c;
    // assume a,b same
    ll newC=b+(b-a);
    if(newC>0 && newC%c==0){
        cout<<"YES\n";
        return;
    }
    // assume a,c same
    if((a+c)%2==0){
        ll newB=(a+c)/2;
        if(newB>0 && newB%b==0){
            cout<<"YES\n";
            return;
        }
    }
    // assume b,c same
    ll newA=b-(c-b);
    if(newA>0 && newA%a==0){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}