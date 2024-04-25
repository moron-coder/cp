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
    vector<int> findOriginalArray(vector<int>& ar) {
        sort(ar.begin(),ar.end());
        map<int,int> mp;
        for(auto it:ar) mp[it]++;
        vector<int> ans;
        for(auto it:mp){
            if(it.second==0) continue;
            if(!mp.count((it.first)<<1)){
                return {};
            }
            // cout<<"at it = "<<it.first<<endl;
            //  it and its double exists in map
            int curFq = it.second, curNum = it.first;
            if(curNum==0){
                if(curFq&1){
                    return {};
                }
                curFq/=2;
            }
            mp[curNum<<1]-=curFq;
            it.second=0;
            for(int i=0;i<curFq;i++){
                ans.push_back(curNum);
            }
        }
        return ans;
    }
};