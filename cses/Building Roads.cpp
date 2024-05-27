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

void bfs(vector<vector<ll>> &edges,int pos,unordered_set<int> &vis){
    queue<int> q;
    q.push(pos);
    vis.insert(pos);

    while (q.size()){
        int cur=q.front();
        q.pop();
        for(auto it:edges[cur]){
            if(!vis.count(it)){
                vis.insert(it);
                q.push(it);
            }
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges(n);
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        x--,y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    unordered_set<int> st;
    vector<pii> ans;
    int prev=0;
    for(int i=0;i<n;i++){
        if(!st.count(i)){
            bfs(edges,i,st);
            if(prev!=i){
                ans.push_back({prev+1,i+1});
                prev=i;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}