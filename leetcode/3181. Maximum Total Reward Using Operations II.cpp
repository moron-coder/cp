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
    int maxTotalReward(vector<int>& ar) {
        //  dp[i] : max reward value if current score is 'i'
        sort(ar.begin(),ar.end());
        bitset<100000> b,m;
        b.set(0);
        int possibleNums=0;
        for(auto it:ar){
            while (possibleNums<it){
                m.set(possibleNums++);
            }
            // m<<it is the set of numbers that can be obtained by adding 'it'
            //  (b&m)<<it is the set of numbers which are possible. all nos in (m<<it) are not possible
            //  as some possibleNums might not be present in ar
            b|= (b&m)<<it;
        }
        for(int i=100000-1;i>=0;i--){
            if(b.test(i)){
                return i;
            }
        }
        return 0;
    }
};