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
    ll x,y,ans=0;
    cin>>x>>y;
    while(y+x){
        ans++;
        if(y==1){
            y=0;
            x=max(0LL,x-11);
        }else if(y>1){
            y-=2;
            x=max(0LL,x-7);
        }else{
            x=max(0LL,x-15);
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}