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
    int minimizeSet(int d1, int d2, int s1, int s2) {
        ll lo=1,hi=1000000000,ans=-1;
        while (lo<=hi){
            ll mid=lo+(hi-lo)/2,lcm=(1LL*d1*d2)/__gcd(d1,d2);
            ll coms=mid-(mid/d1)-(mid/d2)+(mid/lcm);
            ll a=mid-(mid/d1)-coms,b=mid-(mid/d2)-coms;
            // cout<<"for "<<mid<<":\n";
            // cout<<a<<" "<<b<<" "<<coms<<endl;
            if((a+coms)>=s1 && (b+coms)>=s2 && (a+b+coms)>=s1+s2){
                // cout<<mid<<" is ok\n";
                ans=mid;
                hi=mid-1;
            }else{
                // cout<<mid<<" is not ok\n";
                lo=mid+1;
            }
        }
        return lo;
    }
};