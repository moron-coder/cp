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
    int countWays(vector<int>& ar) {
        int ans=0;
        sort(ar.begin(),ar.end());
        if(ar[0]!=0) ans++;     //  no student selected
        if(ar.size()>ar.back()) ans++;  //  all students selected
        for(int j=0;j+1<ar.size();j++){
            if(ar[j+1]-ar[j]>=2){
                int selectedCt = j+1;
                ans+= (selectedCt>=ar[j]+1 && selectedCt<=ar[j+1]-1);
            }
        }
        return ans;
    }
};