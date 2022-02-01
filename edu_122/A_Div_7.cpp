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
    ll rem=n%7;
    if(rem==0){
        cout<<n<<endl;
        return;
    }
    n=(n/10)*10;
    for(ll i=0;i<=9;i++){
        if((n+i)%7==0){
            cout<<n+i<<endl;
            return;
        }
    }
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
