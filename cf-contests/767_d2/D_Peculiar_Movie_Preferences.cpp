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

bool isPal(string &s){
    ll i=0,j=s.size()-1;
    while (i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}

string rv(string s){
    string ans;
    for(ll i=s.size()-1;i>=0;i--){
        ans.push_back(s[i]);
    }
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<string> ar(n);
    for(ll i=0;i<n;i++) cin>>ar[i];
    set<string> alls,prefs;
    for(auto it:ar){
        if(isPal(it) || alls.count(rv(it)) || prefs.count(rv(it)) || alls.count(rv(it.substr(1)))){
            cout<<"YES\n";
            return;
        }
        alls.insert(it);
        it.pop_back();
        prefs.insert(it);
    }
    cout<<"NO\n";
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
