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

void solve() {
    ll a, b,ans;
    cin >> a >> b;
    ans=b-a;
    for (ll a1 = a; a1 < b; a1++) {
        ll b1=0;
        for (ll i = 30; i >= 0; i--) {
            if (a1 & (1 << i)) {
                if ((b & (1 << i)) == 0) {
                    b1 ^= (1 << i);
                    break;
                }
            }else if(b&(1<<i)) b1^=(1<<i);
        }
        ans=min(ans,a1+(a1|b1)+1-a-b);
    }
    cout<<ans<<endl;
}

int main() {
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
