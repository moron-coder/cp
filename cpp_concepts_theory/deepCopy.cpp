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

int main() {
    vector<int> ar = {12,5,11,10,7,3};
    vector<int> ar2=ar;
    ar2[2]=2000;
    for(auto it:ar) cout<<it<<" ";
    cout<<endl;
    for(auto it:ar2) cout<<it<<" ";
    cout<<endl;
    return 0;
}