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

ll di[] = {0,0,1,-1};
ll dj[] = {1,-1,0,0};

void solve(){
    unordered_map<int,char> dirMap;
    dirMap[0]='R';
    dirMap[1]='L';
    dirMap[2]='D';
    dirMap[3]='U';
    string ans;
    unordered_map<int,pair<int,char>> mp;           //  curIdx -> {prevIdx, char}
    ll n,m;
    cin>>n>>m;
    vector<string> v;
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    ll i1=-1,j1=-1;
    for(ll i=0;i<n && i1==-1;i++){
        for(ll j=0;j<m && i1==-1;j++){
            if(v[i][j]=='A'){
                i1=i,j1=j;
            }
        }
    }
    queue<ll> q;
    q.push(i1*m+j1);
    unordered_set<ll> vis;
    vis.insert(i1*m+j1);


    while (q.size()){
        ll cur=q.front();
        q.pop();
        ll curI = cur/m, curJ = cur%m;

        if(v[curI][curJ]=='B'){
            cout<<"YES\n";
            int tmp = curI*m+curJ;
            while (mp.count(tmp)){
                pair<int,char> nxt = mp[tmp];
                ans.push_back(nxt.second);
                tmp = nxt.first;
            }
            cout<<ans.size()<<endl;
            while (ans.size()){
                cout<<ans.back();
                ans.pop_back();
            }
            cout<<endl;
            return;
        }

        for(ll dir=0;dir<4;dir++){
            ll newI = curI+di[dir], newJ = curJ+dj[dir];

            if(newI>=0 && newI<n && newJ>=0 && newJ<m && !vis.count(newI*m+newJ) && v[newI][newJ]!='#'){
                
                vis.insert(newI*m+newJ);
                mp[newI*m+newJ]={cur,dirMap[dir]};
                q.push(newI*m+newJ);
            }
        }
    }
    cout<<"NO\n";
}

int main(){
    ll t=1;
    // cin>>t;
    while (t--){
        solve();
    }
    return 0;
}