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

bool bfs(vector<vector<int>> &edges,int pos,unordered_map<int,int> &mp){
    int team=1;
    queue<int> q;
    mp[pos]=team;
    q.push(pos);
    q.push(-1);
    while (q.size()){
        int cur=q.front();
        q.pop();
        if(cur==-1){
            if(q.empty()) break;
            q.push(-1);
            team = 3-team;
        }else{
            for(auto it:edges[cur]){
                if(mp.count(it)){
                    if(mp[it]!=3-team) {
                        return false;
                    }
                }else{
                    mp[it] = 3-team;
                    q.push(it);
                }
            }
        }
    }
    return true;
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
        edges[y].push_back(x);
    }
    unordered_map<int,int> mp;
    for(ll i=0;i<n;i++){
        if(!mp.count(i)){
            if(!bfs(edges,i,mp)){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<mp[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}