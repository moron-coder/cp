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

ll bs(vector<vector<ll>> &ranked,ll scr){
    ll n=ranked[0].size(),lo=0,hi=n-1,ans=ranked[1].back()+1;
    while (lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(scr<ranked[0][mid]){
            lo=mid+1;
        }else{
            ans=ranked[1][mid];
            hi=mid-1;
        }
    }
    return ans;
}

void solve() {
    ll n, m;
    cin >> n;
    vector<vector<ll>> ranked(2, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++) cin >> ranked[0][i];
    ranked[1][0] = 1;
    for (ll i = 1; i < n; i++) {
        ranked[1][i]=ranked[1][i-1];
        if(ranked[0][i] < ranked[0][i - 1]) ranked[1][i]++;
    }
    cin>>m;
    vector<ll> player(m, -1);
    for (ll i = 0; i < m; i++) cin >> player[i];
    vector<ll> ans;
    for(auto it:player){
        ll pos=bs(ranked,it);
        ans.push_back(pos);
    }
    for(auto it:ans) cout<<it<<endl;
}

int main() {
    solve();
    return 0;
}
