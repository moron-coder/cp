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
    ll x,y,z,ans=0;
    cin>>x>>y>>z;
    if((x+y+z)&1){
        cout<<-1<<endl;
        return;
    }
    priority_queue<int> pq;
    if(x) pq.push(x);
    if(y) pq.push(y);
    if(z) pq.push(z);

    while (pq.size()>=2){
        int b1=pq.top();pq.pop();
        int b2=pq.top();pq.pop();
        int b3=pq.top();pq.pop();

        b1--,b3--,ans++;
        if(b1) pq.push(b1);
        pq.push(b2);
        if(b3) pq.push(b3);
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