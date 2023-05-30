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
    ll n;
    cin>>n;
    string ans;
    vector<string> v;
    for(int i=0;i<n-2;i++){
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    ans.push_back(v[0][0]);
    for(int i=1;i<v.size();i++){
        if(v[i][0]==v[i-1][1]){
            // match
            ans.push_back(v[i][0]);
        }else{
            ans.push_back(v[i-1][1]);
            ans.push_back(v[i][0]);
        }
    }
    ans.push_back(v.back()[1]);
    if(ans.size()<n) ans.push_back(v.back()[1]);
    cout<<ans<<endl;
}

int main() {
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}