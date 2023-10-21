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
    bool isIdealPermutation(vector<int>& ar) {
        int n=ar.size();
        int *idx = new int[n]();
        for(int i=0;i<ar.size();i++) idx[ar[i]]=i;
        int maxIdx=-1;
        for(int i=0;i<n;i++){
            if(maxIdx>1+idx[i]){
                // a smaller number has occurred at a later index
                return false;
            }
            maxIdx = max(maxIdx,idx[i]);
        }
        return true;
    }
};