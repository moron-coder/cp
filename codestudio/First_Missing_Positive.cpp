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
    int firstMissingPositive(vector<int>& ar) {
        int n = ar.size();
        for (int i = 0; i < n; i++) {
            if (ar[i] <= 0) ar[i] = n + 1;  // remove this from picture
        }
        for (int i = 0; i < n; i++) {
            if (abs(ar[i]) <= n && abs(ar[i]) >= 1) {
                // this was not already -ve, but it is made -ve during the traversal process
                if (ar[abs(ar[i]) - 1] > 0) ar[abs(ar[i]) - 1] *= -1;  //  we need to check if it's already -ve
                // else, we'll end up making a visited index as unvisited
            }
        }
        for (int i = 0; i < n; i++)
            if (ar[i] > 0) return i + 1;
        return n + 1;
    }
};