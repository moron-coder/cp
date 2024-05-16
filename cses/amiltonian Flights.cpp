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
#define ll long long int
#define mod 1000000007

ll dp[1<<20][21];

ll help(vector<vector<int>> &edges,ll pos,ll prevs){
    int n=edges.size();
    if(pos==n-1){
        return prevs==((1<<n)-1);
    }

    if(dp[prevs][pos]!=-1) return dp[prevs][pos];
    ll ans=0;
    for(auto it:edges[pos]){
        if(prevs&(1<<it)){
            continue;
        }
        ll small = help(edges,it,prevs^(1<<it));
        ans = (ans+small+mod)%mod;
    }
    return dp[prevs][pos] = (ans+mod)%mod;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n,vector<int>());
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        edges[x].push_back(y);
    }
    cout<<help(edges,0,1)<<endl;   
}

int main(){
    solve();
    return 0;
}