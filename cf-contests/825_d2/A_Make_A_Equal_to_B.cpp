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

class uf {
   public:
    int *size, *par;
    int cap;
    uf(int n) {
        cap = n;
        size = new int[n]();
        par = new int[n]();
        for (int i = 0; i < n; i++) par[i] = i, size[i] = 1;
    }

    int getPar(int x) {
        if (par[x] == x) return x;
        return par[x] = getPar(par[x]);
    }

    void merge(int x, int y) {
        x = getPar(x), y = getPar(y);
        if (x == y) return;
        if (size[x] < size[y])
            par[x] = y, size[y] += size[x];
        else
            par[y] = x, size[x] += size[y];
    }
};

vector<int> KMP(string s) {
    vector<int> lps(s.size(), 0);
    for (int i = 1; i < s.length(); i++) {
        int j = lps[i - 1];
        while (j > 0 && s[j] != s[i]) j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }
    return lps;
}

void solve() {
    ll n,oa=0,ob=0,del=0;
    cin>>n;
    vector<ll> a(n,-1),b(n,-1);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]) oa++;
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        if(b[i]) ob++;
    }
    bool same=true;
    for(ll i=0;i<n;i++){
        if(a[i]!=b[i]){
            same=false;
            del++;
        }
    }
    if(same){
        cout<<0<<endl;
        return;
    }
    if(oa==ob){
        cout<<1<<endl;
        return;
    }
    cout<<min(del,1+abs(oa-ob))<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
