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
    int findLeastNumOfUniqueInts(vector<int>& ar, int k) {
        int n=ar.size();
        vector<pii> v;
        unordered_map<int,int> mp;
        for(auto it:ar) mp[it]++;
        for(auto it:mp) v.push_back({it.second,it.first});      //  fq, element
        sort(v.begin(),v.end());
        int remCt=0,ans=v.size();
        for(int i=0;i<v.size();i++){
            if(remCt+v[i].first<=k){
                remCt+=v[i].first;
                ans--;
            }else{
                break;
            }
        }
        return ans;
    }
};