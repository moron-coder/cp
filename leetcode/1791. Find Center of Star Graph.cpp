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
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        int *ct=new int[n]();
        for(auto it:edges) ct[it[0]-1]++,ct[it[1]-1]++;
        for(int i=0;i<n;i++) if(ct[i]==n-1) return i+1;
        return -1;
    }
};