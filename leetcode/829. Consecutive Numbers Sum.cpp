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
    int consecutiveNumbersSum(int n) {
        int ans=0;
        n=(n<<1);
        for(ll i=1;i*i<=n;i++){
            if(n%i==0){
                int f1=n/i,f2=i;
                if(f1<f2) swap(f1,f2);
                if((f1^f2)&1){
                    ans++;
                }
            }
        }
        return ans;
    }
};