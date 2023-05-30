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
    double cHealth,cAttack,mHealth,mAttack,coins,upAttack,upHealth;
    cin>>cHealth>>cAttack>>mHealth>>mAttack>>coins>>upAttack>>upHealth;
    for(double i=0;i<=coins;i++){
        double newCAttack = (cAttack+i*upAttack), newCHealth = (cHealth+(coins-i)*upHealth);
        double cMovesReq = ceil(mHealth/newCAttack), mMovesReq = ceil(newCHealth/mAttack);
        if(cMovesReq<=mMovesReq){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
