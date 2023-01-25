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
    void nextPermutation(vector<int>& ar) {
        int n=ar.size(),bigs=ar.back(),pos=-1;
        for(int i=n-2;i>=0;i--){
            if(ar[i]<bigs){
                pos=i;
                break;
            }
            bigs=max(bigs,ar[i]);
        }
        if(pos==-1) return;
        int justBigPos=-1;
        for(int i=pos+1;i<n;i++){
            if(ar[i]>ar[pos] && (justBigPos==-1 || ar[i]<ar[justBigPos])){
                justBigPos=i;
            }
        }
        swap(ar[pos],ar[justBigPos]);
        sort(ar.begin()+pos+1,ar.end());
    }
};