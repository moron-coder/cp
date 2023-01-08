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

int di[]={1,0,-1,0};
int dj[]={0,1,0,1};

void solve(){
    ll n,i=0,j=0,last=1,dir=0;
    cin>>n;
    vector<vector<ll>> ar(n,vector<ll>(n,-1));
    for(int it=0;it<n*n;it++){
        // cout<<i<<","<<j<<endl;
        if(it&1){
            ar[i][j]=n*n+1-last;
            last++;
        }else{
            ar[i][j]=last;
        }
        int newI=i+di[dir],newJ=j+dj[dir];
        if(newI>=0 && newI<n && newJ>=0 && newJ<n && (dir&1)==0){
            // ok
        }else{
            dir=(dir+1)%4;
            newI=i+di[dir],newJ=j+dj[dir];
        }
        i=newI,j=newJ;
    }
    for(auto it:ar){
        for(auto it1:it) cout<<it1<<" ";
        cout<<endl;
    }
}

int main(){
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}