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


    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // get LCA for each query then calculate distance from LCA
        vector<int> ans;
        for(auto it:queries){
            unordered_map<int,int> parsA;
            int a=it[0],b=it[1],dis=0,dis2=0;
            while (a){
                parsA.insert({a,dis});
                a/=2;
                dis++;
            }
            while (b){
                if(parsA.count(b)){
                    ans.push_back(dis2+parsA[b]);
                    break;
                }
                b/=2;
                dis2++;
            }
        }
        return ans;
    }
};