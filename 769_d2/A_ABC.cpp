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
    string s;
    cin>>s;
    if(n<3){
        if(n==1 || s[0]!=s[1]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
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
