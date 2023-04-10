#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define ll long long int

class Solution {
public:
    int fastMod(int n){
        if(n==0) return 1;
        int ans=1;
        if(n&1){
            ans=2;
        }
        int halfAns=fastMod(n/2);
        ans=(1LL*ans*halfAns)%mod;
        ans=(1LL*ans*halfAns)%mod;
        return ans;
    }

    int countWays(vector<vector<int>>& ar) {
        sort(ar.begin(),ar.end());
        vector<vector<int>> stk;
        for(auto it:ar){
            if(stk.empty() || stk.back()[1]<it[0]){
                stk.push_back(it);
            }else{
                stk.back()[1]=max(stk.back()[1],it[1]);
            }
        }
        return fastMod(stk.size());
    }
};