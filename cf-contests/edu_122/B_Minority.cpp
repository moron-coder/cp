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
    string s;
    cin>>s;
    ll n=s.size(),ans=0,ct0=0,ct1=0;
    for(auto it:s){
        if(it=='0') ct0++;
        else ct1++;
    }
    if(ct0!=ct1){
        cout<<min(ct1,ct0)<<endl;
    }else{
        cout<<ct1-1<<endl;
    }
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
