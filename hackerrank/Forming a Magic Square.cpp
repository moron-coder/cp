#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<long, long>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define ll long long int

ll curCost;

bool isMagic(vector<ll> &ar){
    vector<ll> vSum(3,0),hSum(3,0),dSum(2,0);
    for(ll i=0;i<3;i++){
        // dSum[0]+=ar[i][i];
        // dSum[1]+=ar[i][2-i];
        // for(ll j=0;j<3;j++){
        //     hSum[i]+=ar[i][j];
        //     vSum[j]+=ar[i][j];
        // }
        // ar[i][j] is written as ar[i*3+j];
        dSum[0]+=ar[i*3+i];
        dSum[1]+=ar[i*3+2-i];
        for(ll j=0;j<3;j++){
            hSum[i]+=ar[i*3+j];
            vSum[j]+=ar[i*3+j];
        }
    }
    ll sum=dSum[0];
    for(auto it:vSum) if(it!=sum) return false;
    for(auto it:hSum) if(it!=sum) return false;
    for(auto it:dSum) if(it!=sum) return false;
    return true;
}

void rec(vector<ll> &v,vector<ll> &ar,ll pos,vector<bool> &used){
    if(pos>=9){
        if(isMagic(ar)){
            ll cur=0;
            for(ll i=0;i<9;i++) cur+=abs(ar[i]-v[i]);
            curCost=min(curCost,cur);
        }
        return;
    }
    for(ll i=0;i<9;i++){
        // filling i+1 in ar[pos]
        if(!used[i]){
            ar[pos]=i+1;
            used[i]=true;
            rec(v,ar,pos+1,used);
            used[i]=false;
        }
    }
}

void solve(){
    curCost=INT_MAX;
    vector<ll> v(9,-1),ar(9,-1);
    vector<bool> used(9,false);
    for(ll i=0;i<9;i++) cin>>v[i];
    rec(v,ar,0,used);
    cout<<curCost<<endl;
}

int main() {
    solve();
    return 0;
}
