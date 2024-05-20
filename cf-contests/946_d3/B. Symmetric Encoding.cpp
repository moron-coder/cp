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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    int *fq=new int[26]();
    for(auto it:s){
        fq[it-'a']++;
    }
    vector<int> v;
    for(int i=0;i<26;i++){
        if(fq[i]) v.push_back(i);
    }
    map<int,int> mp;
    for(int i=0;i<v.size();i++){
        mp[v[i]]=v[v.size()-1-i];
    }
    string org;
    for(int i=0;i<s.size();i++){
        int curCh = s[i]-'a';
        org.push_back(mp[curCh]+'a');
    }
    cout<<org<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}