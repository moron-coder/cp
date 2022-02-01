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

bool cmp(pll x,pll y){
    if(x.second==y.second) return x.first<y.first;
    return x.second<y.second;
}

void solve() {
    ll n,ans=1,takenId=0,lastIntersect=INT_MIN;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return;
    }
    vector<pll> ar(n);
    for(ll i=0;i<n;i++) cin>>ar[i].first>>ar[i].second;
    sort(ar.begin(),ar.end(),cmp);
    for(ll i=1;i<n;i++){
        if(ar[takenId].second<ar[i].first){
            // take it
            ans++;
            takenId=i;
            // since no intersection happenned, dont change lastIntersect
        }else if(lastIntersect<ar[i].first){
            ans++;
            lastIntersect=ar[takenId].second;
            takenId=i;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
