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
    bool isPun(int n,int sum,int nOrig){
        if(!n){
            return sum==nOrig;
        }
        int md=0,pw=1;
        while(n){
            md+=(n%10)*pw;
            pw*=10;
            n/=10;
            if(isPun(n,sum+md,nOrig)){
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans=0;
        for(int i=0;i<=n;i++){
            bool bl = isPun(i*i,0,i);
            ans+=(bl)?i*i:0;
        }
        return ans;
    }
};