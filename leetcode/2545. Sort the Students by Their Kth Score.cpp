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

int pos;

static bool cmp(vector<int> &x, vector<int> &y) {
    return x[pos] > y[pos];
}

class Solution {
   public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &ar, int k) {
        pos = k;
        sort(ar.begin(), ar.end(), cmp);
        return ar;
    }
};