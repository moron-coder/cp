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

void solve() {
    string s;
    cin >> s;
    double len = sqrt(s.size());
    ll ro = ceil(len), col =ro, pos = 0;
    vector<vector<char>> ar(ro, vector<char>(col, '.'));
    for (ll i = 0; pos<s.size() && i < ro; i++) for (ll j = 0; pos<s.size() && j < col; j++) ar[i][j] = s[pos++];
    for (ll j = 0; j < col; j++) {
        for (ll i = 0; i < ro && ar[i][j]!='.' ; i++) cout<<ar[i][j];
        cout<<" ";
    }
    cout<<endl;
}

int main() {
    solve();
    return 0;
}