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
    long long flowerGame(int n, int m) {
        //  number of unordered pairs with odd sum
        long long ans=0;
        int x=(m&1)?m-1:m;
        int y=(m&1)?m:m-1;
        for(int i=1;i<=n;i++){
            ans += (i&1)?1+(x-2)/2:1+(y-1)/2;
        }
        return ans;
    }
};