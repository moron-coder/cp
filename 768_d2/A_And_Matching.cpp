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
    ll n,k;
    cin>>n>>k;
    if(k>n-1){
        cout<<-1<<endl;
        return;
    }else if(k==n-1){
        if(n==4 || n==2){
            cout<<-1<<endl;
            return;
        }
        cout<<k<<" "<<n-2<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<0<<" "<<n-4<<endl;
        for(ll i=2;i<n/2;i++){
            if(i==k || i==3) continue;
            cout<<i<<" "<<n-1-i<<endl;
        }
    }else if(k==0){
        for(ll i=0;i<n/2;i++) cout<<i<<" "<<n-1-i<<endl;
    }else{
        cout<<k<<" "<<n-1<<endl;
        cout<<0<<" "<<n-1-k<<endl;
        for(ll i=1;i<n/2;i++){
            if(i==k || i==n-1-k) continue;
            cout<<i<<" "<<n-1-i<<endl;
        }
    }
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
