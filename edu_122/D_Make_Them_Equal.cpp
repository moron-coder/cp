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

vector<ll> ct(1001,-1);

void make(){
    ll n=ct.size(),steps=0;
    vector<bool> vis(1001,false);
    queue<ll> q;
    q.push(1);
    q.push(-1);
    vis[1]=true;
    while (q.size()){
        ll cur=q.front();q.pop();
        if(cur==-1){
            if(q.empty()) break;
            q.push(-1);
            steps++;
        }else{
            ct[cur]=steps;
            for(ll i=1;i<=cur;i++){
                if(cur+(cur/i)>1000) continue;
                if(!vis[cur+(cur/i)]){
                    vis[cur+(cur/i)]=true;
                    q.push(cur+(cur/i));
                }
            }
        }
    }
}

ll dp[12001][1001];

ll help(vector<ll> &b,vector<ll> &c,ll pos,ll k){
    ll n=b.size(),ans=0;
    if(pos>=n) return 0;
    if(dp[k][pos]!=-1) return dp[k][pos];
    ans=help(b,c,pos+1,k);
    if(ct[b[pos]]<=k) ans=max(ans,help(b,c,pos+1,k-ct[b[pos]])+c[pos]);
    return dp[k][pos]=ans;
}

void solve(){
    ll n,k,ans=0;
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    k=min(k,12000LL);
    vector<ll> b(n,-1),c(n,-1);
    for(ll i=0;i<n;i++) cin>>b[i];
    for(ll i=0;i<n;i++) cin>>c[i];
    // to go from 1 to b[i], we need ct[b[i]] operations
    ans=help(b,c,0,k);
    cout<<ans<<endl;
    
}

int main() {
    make();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
