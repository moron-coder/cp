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
    int minimumRightShifts(vector<int>& ar) {
        int minElIdx=0,n=ar.size();
        for(int i=0;i<n;i++){
            if(ar[i]<ar[minElIdx]) minElIdx=i;
        }
        for(int i=(minElIdx+1)%n;i!=minElIdx;i=(i+1)%n){
            if(ar[i]<ar[(i-1+n)%n]){
                return -1;
            }
        }
        return (n-minElIdx)%n;
    }
};