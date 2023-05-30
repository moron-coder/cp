#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define ll long long int

class mexCalc{
    set<ll> cpm;
    public:
    mexCalc(ll n){
        cpm.clear();
        for(ll i=0;i<=n;i++) cpm.insert(i);
    }
    void add(ll n){
        if(cpm.count(n)) cpm.erase(n);
    }
    ll mexVal(){
        return *cpm.begin();
    }
};

void rec(vector<ll> &sufMex,vector<ll> &ans,ll pos,vector<ll> &ar){
    if(pos>=sufMex.size()) return;
    // find the first prefix index 'id' such that sufMex[pos]=prefixMex({ar[pos],..,ar[id]});
    set<ll> cur;
    for(ll id=pos;id<ar.size();id++){
        // I need to find the first index 'id' such that mex({ar[pos],ar[pos+1],..,ar[id]}) = sufMex[pos]
        // If ar[id]>sufMex[pos] then I simply ignore ar[id]
        // check if sufMex[pos]==cur.size()
        if(ar[id]<sufMex[pos]) cur.insert(ar[id]);
        if(sufMex[pos]==cur.size()){
            ans.push_back(sufMex[pos]);
            rec(sufMex,ans,id+1,ar);
            return;
        }
    }
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> ar(n,-1),sufMex(n,-1);
    for(ll i=0;i<n;i++) cin>>ar[i];
    mexCalc mxc(n);
    for(ll i=n-1;i>=0;i--){
        mxc.add(ar[i]);
        sufMex[i]=mxc.mexVal();
    }
    vector<ll> ans;
    rec(sufMex,ans,0,ar);
    cout<<ans.size()<<endl;
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
