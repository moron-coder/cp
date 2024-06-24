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
    const static int MAX_VAL = 10000000;
public:
    int firstMissingPositive(vector<int>& ar) {
        for(auto &it:ar) if(it<=0) it=MAX_VAL;
        int n=ar.size();
        bool nFound=false;
        for(auto it:ar){
            if(abs(it)==ar.size()) nFound=true;
            if(abs(it)<ar.size() && ar[abs(it)]>0){
                ar[abs(it)]*=-1;
            }
        }
        for(int i=1;i<ar.size();i++){
            if(ar[i]>0) return i;
        }
        return nFound ? ar.size()+1 : ar.size();
    }
};