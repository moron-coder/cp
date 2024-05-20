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
    ll n,ans=0;
    cin>>n;
    vector<ll> ar(n,-1);
    for(int i=0;i<n;i++) cin>>ar[i];
    map<pii,map<int,int>> lastTwo,firstTwo,firstLast;
    for(int i=0;i+2<n;i++){
        lastTwo[{ar[i+1],ar[i+2]}][ar[i]]++;
        firstLast[{ar[i],ar[i+2]}][ar[i+1]]++;
        firstTwo[{ar[i],ar[i+1]}][ar[i+2]]++;
    }
    for(auto it:firstLast){
        ll tot=0;
        for(auto it1:it.second){
            // ans+=pow(it.second.size()-1,it.second.size())*it1.second;
            tot+=it1.second;
        }
        // cout<<"{"<<it.first.first<<"-"<<it.first.second<<"} tot = "<<tot<<endl;
        for(auto it1:it.second){
            // cout<<it1.first<<" contributes "<<(tot-it1.second)*(it1.second)<<endl;
            ans+=(tot-it1.second)*(it1.second);
        }
    }
    
    for(auto it:lastTwo){
        ll tot=0;
        for(auto it1:it.second){
            // ans+=pow(it.second.size()-1,it.second.size())*it1.second;
            tot+=it1.second;
        }
        // cout<<"{"<<it.first.first<<"-"<<it.first.second<<"} tot = "<<tot<<endl;
        for(auto it1:it.second){
            // cout<<it1.first<<" contributes "<<(tot-it1.second)*(it1.second)<<endl;
            ans+=(tot-it1.second)*(it1.second);
        }
    }
    for(auto it:firstTwo){
        ll tot=0;
        for(auto it1:it.second){
            // ans+=pow(it.second.size()-1,it.second.size())*it1.second;
            tot+=it1.second;
        }
        // cout<<"{"<<it.first.first<<"-"<<it.first.second<<"} tot = "<<tot<<endl;
        for(auto it1:it.second){
            // cout<<it1.first<<" contributes "<<(tot-it1.second)*(it1.second)<<endl;
            ans+=(tot-it1.second)*(it1.second);
        }
    }
    cout<<ans/2<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}