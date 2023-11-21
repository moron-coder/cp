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
    vector<string> findHighAccessEmployees(vector<vector<string>>& ar) {
        vector<string> ans;
        sort(ar.begin(),ar.end());
        for(int i=2;i<ar.size();i++){
            if((ans.empty() || ans.back()!=ar[i][0]) && ar[i-2][0]==ar[i][0] && stoi(ar[i][1])-stoi(ar[i-2][1])<100){
                ans.push_back(ar[i][0]);
            }
        }
        return ans;
    }
};