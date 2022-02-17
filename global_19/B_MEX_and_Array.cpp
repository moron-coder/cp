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

ll dp[101][101][101];
ll mexVal[101][101];

ll getVal(vector<ll> &ar, ll pos, ll ends, ll parts) {
    ll n = ar.size(), ans = -2;
    if (parts < 0) return -2;
    if (pos > ends) {
        if (parts) return -2;
        return 0;
    }
    if (dp[pos][ends][parts] != -1) return dp[pos][ends][parts];
    for (ll i = pos; i <= ends; i++) {
        if (parts == 1 && i != ends) continue;  //  to prevent parts<0
        // ar[pos]~ar[i] is in the current segment
        ll tmp = getVal(ar, i + 1, ends, parts - 1);
        if (tmp != -2) ans = max(ans, mexVal[pos][i] + tmp);
    }
    return dp[pos][ends][parts] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    memset(mexVal, -1, sizeof(mexVal));
    ll n, ans = 0;
    cin >> n;
    vector<ll> ar(n, -1);
    for (ll i = 0; i < n; i++) cin >> ar[i];
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            set<ll> st;
            for (ll it = 0; it <= j - i + 2; it++) st.insert(it);
            for (ll it = i; it <= j; it++) if (st.count(ar[it])) st.erase(ar[it]);
            mexVal[i][j]=*st.begin();
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            ll maxVal = 0;
            for (ll parts = 1; parts <= (j - i + 1); parts++) {
                ll tmp = getVal(ar, i, j, parts);
                if (tmp == -2) continue;
                maxVal = max(maxVal, parts + tmp);
            }
            ans += maxVal;
        }
    }
    cout << ans << endl;
}

int main() {
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
