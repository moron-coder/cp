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
    void updateMap(string &it, unordered_map<string,int> &mp, bool insert){
        for(int i=0;i<it.size();i++){
            string tmp;
            for(int j=i;j<it.size();j++){
                tmp.push_back(it[j]);
                insert ? mp[tmp]++ : mp[tmp]--;
                if(mp[tmp]==0){
                    mp.erase(tmp);
                }
            }
        }
    }

    string getAns(string &s, unordered_map<string,int> &mp){
        int n=s.size();
        string ans;

        for(int i=0;i<n;i++){
            string tmp;
            for(int j=i;j<n;j++){
                tmp.push_back(s[j]);
                if(!mp.count(tmp) && (ans.size()==0 || ans.size()>tmp.size() || (ans.size()==tmp.size() && tmp<ans))){
                    ans=tmp;
                }
            }
        }
        return ans;
    }

public:
    vector<string> shortestSubstrings(vector<string>& ar) {
        unordered_map<string,int> mp;
        for(auto it:ar){
            updateMap(it,mp,true);
        }

        vector<string> ans;

        for(auto it:ar){
            updateMap(it,mp,false);
            ans.push_back(getAns(it,mp));
            updateMap(it,mp,true);
        }
        return ans;
    }
};