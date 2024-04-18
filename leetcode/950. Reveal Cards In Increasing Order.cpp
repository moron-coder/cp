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
    vector<int> deckRevealedIncreasing(vector<int>& ar) {
        deque<int> indexes;
        int n=ar.size();
        for(int i=1;i<=n;i++){
            indexes.push_back(i);
        }
        vector<int> orders;
        while (indexes.size()){
            orders.push_back(indexes.front());
            indexes.pop_front();
            if(indexes.empty()) break;
            int tmp=indexes.front();
            indexes.pop_front();
            indexes.push_back(tmp);
        }
        sort(ar.begin(),ar.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[orders[i]-1]=ar[i];
        }
        return ans;
    }
};