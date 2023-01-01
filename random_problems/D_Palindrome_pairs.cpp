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

void solve() {
    string s;
    cin>>s;
    vector<vector<int>> dp(2001,vector<int>(2001,0));
    // memset(dp,0,sizeof(dp));
    ll n=s.size(),ans=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j]=1;
                continue;
            }else if(i+1>j-1){
                dp[i][j]=(s[i]==s[j]);
                continue;
            }else{
                dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
            }
        }
    }
    int *suf=new int[n]();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(dp[i][j]){
                suf[i]++;
            }
        }
    }
    for(int i=n-2;i>=0;i--) suf[i]+=suf[i+1];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j+1>=n) continue;
            if(dp[i][j]) ans+=suf[j+1];
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
    return 0;
}