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
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n=s.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                int cur=0;
                for(int j=i;j<min(n,i+31);j++){
                    cur=(cur<<1);
                    cur+=(s[j]-'0');
                    if(mp.count(cur)) continue;
                    mp[cur]={i,j};
                }
            }else{
                if(mp.count(0)) continue;
                mp[0]={i,i};
            }
        }
        vector<vector<int>> ans;
        for(vector<int> v:queries){
            int n1=v[0],n2=v[1];
            if(mp.count(n1^n2)){
                ans.push_back(mp[n1^n2]);
            }else{
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};