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
    long long largestPerimeter(vector<int>& ar) {
        int len=0,sum=0,ans=0;
        for(auto it:ar){
            len++;
            cout<<len<<" "<<sum<<endl;
            if(len>2 && it>sum){
                ans=sum+it;
            }
            sum+=it;
        }
        return ans;
    }
};