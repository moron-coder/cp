#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ar) {
        sort(ar.begin(),ar.end());
        vector<vector<int>> stk;
        for(auto it:ar){
            if(stk.empty() || stk.back()[1]<it[0]){
                stk.push_back(it);
            }else{
                stk.back()[1]=max(stk.back()[1],it[1]);
            }
        }
        return stk;
    }
};