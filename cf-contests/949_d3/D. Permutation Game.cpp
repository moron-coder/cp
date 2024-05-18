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

ll rec(vector<ll> &ar, vector<ll> &jumps,ll pos,ll k){
    ll ans=ar[pos];
    if(!k) return ans;

    ll ans1 = rec(ar,jumps,pos,k-1);
    ll ans2 = rec(ar,jumps,jumps[pos],k-1);

    return max(ans1,ans2)+ans;
}

void solve(){
    ll n,k,b,s;
    cin>>n>>k>>b>>s;
    b--,s--;
    vector<ll> ar(n,-1),pos(n,-1);
    for(ll i=0;i<n;i++){
        cin>>pos[i];
        pos[i]--;
    }
    for(ll i=0;i<n;i++){
        cin>>ar[i];
    }

    //  bodya

    vector<ll> bodyaIndexes(1,b);
    ll tmp=b;

    vector<bool> visB(n,false);

    while (!visB[tmp]){
        visB[tmp]=true;
        tmp = pos[tmp];
        bodyaIndexes.push_back(tmp);
    }

    // for(auto it:bodyaIndexes){
    //     cout<<it<<" ";
    // }    
    // cout<<endl;

    ll maxPos=0,maxScr=ar[bodyaIndexes[0]];
    for(ll i=0;i<min((ll)bodyaIndexes.size(), k);i++){
        if(ar[bodyaIndexes[i]]>maxScr){
            maxScr = ar[bodyaIndexes[i]];
            maxPos = i;
        }
    }

    ll bodyaScr = 0, bk=k;
    for(ll i=0;i<=maxPos;i++){
        bk--;
        bodyaScr+=ar[bodyaIndexes[i]];
    }
    bodyaScr+=bk*ar[bodyaIndexes[maxPos]];
    // cout<<"bodya : "<<bodyaScr<<endl;

    ///////////////////////////////////////////////////////////////////

    //  sasha

    vector<ll> sashaIndexes(1,s);
    tmp=s;

    vector<bool> visS(n,false);

    while (!visS[tmp]){
        visS[tmp]=true;
        tmp = pos[tmp];
        sashaIndexes.push_back(tmp);
    }

    maxPos=0,maxScr=ar[sashaIndexes[0]];
    for(ll i=0;i<min((ll)sashaIndexes.size(), k);i++){
        if(ar[sashaIndexes[i]]>maxScr){
            maxScr = ar[sashaIndexes[i]];
            maxPos = i;
        }
    }

    ll sashaScr = 0, sk=k;
    for(ll i=0;i<=maxPos;i++){
        sk--;
        sashaScr+=ar[sashaIndexes[i]];
    }
    sashaScr+=sk*ar[sashaIndexes[maxPos]];
    // cout<<"sasha : "<<sashaScr<<endl;

    if(bodyaScr>sashaScr){
        cout<<"Bodya\n";
    }else if(sashaScr>bodyaScr){
        cout<<"Sasha\n";
    }else{
        cout<<"Draw\n";
    }
    
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}
