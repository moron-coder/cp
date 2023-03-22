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
    int maximizeGreatness(vector<int>& ar) {
        int n=ar.size(),ans=0;
        sort(ar.begin(),ar.end());
        queue<int> q;
        for(auto it:ar){
            if(q.size() && q.front()<it){
                ans++;
                q.pop();
            }
            q.push(it);
        }
        return ans;
    }
};