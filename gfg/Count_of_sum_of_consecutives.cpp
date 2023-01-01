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


class Solution {
  public:
    int getCount(int n) {
        if(n==1) return 0;
        int ans=0;
        for(ll i=1;2*n-i*(i+1)>0;i++){
            if(((2*n-i*(i+1))%(2*(i+1)))==0) ans++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    ll t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
    cout<<s.getCount(n)<<endl;
    }
    return 0;
}