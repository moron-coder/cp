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

bool dfs(int pos,vector<vector<int>> &edges,int *vis,vector<int> &ans){
    // vis.insert(pos);
    vis[pos]=1;
    for(auto it:edges[pos]){
        if(vis[it]==1){
            ans.push_back(it+1);
            ans.push_back(pos+1);
            vis[pos]=2;
            return true;
        }else if(vis[it]==0 && dfs(it,edges,vis,ans)){
            if(ans.size()==1 || ans[0]!=ans.back()) {
                ans.push_back(pos+1);
            }
            vis[pos]=2;
            return true;
        }
    }
    vis[pos]=2;
    return false;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n);
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        x--,y--;
        edges[x].push_back(y);
    }
    vector<int> ans;
    int *vis = new int[n]();
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(dfs(i,edges,vis,ans)){
                cout<<ans.size()<<endl;
                while (ans.size()){
                    cout<<ans.back()<<" ";
                    ans.pop_back();
                }
                cout<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}